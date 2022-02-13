package src.crawler;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import src.book.Book;

import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

/**
 * @author Liu Yuan
 * @create 2021-10-23-16:39
 * @describe 爬虫类，数据来自纵横小说网
 */
public class Crawler
{
    static Connection connection = null;
    static PreparedStatement statement = null;

    public static List<Book> readBook() throws IOException
    {
        /**
         * @function readBook
         * @param []
         * @return java.util.List<src.book.Book>
         * @description 将书名，URL，作者，分类，是否完结，更新时间，介绍保存在Book对象中，并放到链表中
         * @author Liu Yuan
         * @date 2021/10/23
         */
        String bookName = null;                         //存储书名
        String bookUrl = null;                          //存储URL
        String bookInfo = null;                         //存储作者、分类、是否完结、更新时间
        String author = null;                           //作者
        String style = null;                            //分类
        boolean finished = false;                       //是否完结
        String updateTime = null;                       //更新时间
        String bookIntro = null;                        //存储介绍
        Elements Elements_bookName = null;              //存储一本书的相关信息
        List<Book> books = new ArrayList<Book>();       //将书的书名和URL保存在对象的链表中
        String[] bookString = null;                     //字符串分割，取出URL
        String[] bookInfoSplit = null;                  //字符串分割，取出相关信息
        Book newBook = null;                            //新增加的书

        for (int i = 1; i <= 16; i++)
        {
            String url = "http://book.zongheng.com/store/c0/c0/b0/u0/p" + i + "/v9/s1/t5/u0/i1/ALL.html";  //链接网页
            Document document = Jsoup.parse(new URL(url), 10000);                      //将当前网页保存为文档
            System.out.println(document);
            Elements bookList = document.getElementsByClass("store_collist");           //存储所有书的相关信息

            for (Element book : bookList)
            {
                //将书名，URL，相关信息，介绍提取出来
                Elements_bookName = book.getElementsByClass("bookinfo");
                for (Element element : Elements_bookName)
                {
                    //提取书名
                    bookName = element.getElementsByClass("bookname").text();

                    //提取URL
                    bookString = element.toString().split("\"");
                    for (String name : bookString)
                    {
                        if (name.endsWith("html"))
                        {
                            bookUrl = name;
                            break;
                        }
                    }

                    //提取信息
                    bookInfo = element.getElementsByClass("bookilnk").text();
                    bookInfoSplit = bookInfo.split("\\| ");
                    author = bookInfoSplit[0];
                    style = bookInfoSplit[1];
                    finished = bookInfoSplit[2].equals("已完结") ? true : false;
                    updateTime = bookInfoSplit[3];

                    //提取介绍
                    bookIntro = element.getElementsByClass("bookintro").text();

                    //写入链表
                    newBook = new Book(bookName, bookUrl, author, style, finished, updateTime, bookIntro);
                    books.add(newBook);
                }
            }
        }
        return books;
    }

    public static void write_books(List<Book> books)
    {
        /**
         * @function write
         * @param [title, name, dynasty, document]
         * @return void
         * @description 将读取到的文件写到 MySQL 中
         * @author Liu Yuan
         * @date 2021/10/23
         */
        String sql ="insert into books values(null,?,?,?,?,?,?,?)";
        int count = 0;
        try
        {
            connection = utils.getConnection();
            statement = connection.prepareStatement(sql);
            for (Book book : books)
            {
                statement.setString(1, book.getBookName());
                statement.setString(2, book.getBookUrl());
                statement.setString(3, book.getAuthor());
                statement.setString(4, book.getStyle());
                statement.setString(5, book.getFinished()?"已完结":"未完结");
                statement.setString(6, book.getUpdateTime());
                statement.setString(7, book.getBookIntro());
                statement.executeUpdate();
                System.out.println("第 " + ++count + " 条写入成功");
            }
        } catch (SQLException throwables)
        {
            throwables.printStackTrace();
        }
    }

    public static List<Book> readBookData()
    {
        /**
         * @function readBookData
         * @param []
         * @return java.util.List<src.book.Book>
         * @description 将 books 表中的数据读到链表中
         * @author Liu Yuan
         * @date 2021/10/24
         */
        String sql ="select * from books";

        String name = null;
        String url = null;
        String author = null;
        String style = null;
        Boolean finished  = null;
        String updateTime  = null;
        String bookIntro  = null;

        Book book = null;
        List<Book> books = new ArrayList<Book>();
        try
        {
            connection = utils.getConnection();
            statement = connection.prepareStatement(sql);
            ResultSet resultSet = statement.executeQuery();
            while(resultSet.next())
            {
                name = resultSet.getString("name");
                url = resultSet.getString("url");
                author = resultSet.getString("author");
                style = resultSet.getString("style");
                finished = resultSet.getString("finished").equals("已完结") ? true : false;
                updateTime = resultSet.getString("updateTime");
                bookIntro = resultSet.getString("bookIntro");

                book = new Book(name,url,author,style,finished,updateTime,bookIntro);
                books.add(book);
            }
        } catch (SQLException throwables)
        {
            throwables.printStackTrace();
        }

        return books;
    }

    public static List<Book> getBookCode()
    {
        /**
         * @function getBookCode
         * @param []
         * @return java.util.List<java.lang.String>
         * @description 获取书的代码，方便构造url，访问目录
         * @author Liu Yuan
         * @date 2021/10/24
         */
        List<Book> books = readBookData();      //从数据库中读取对象
        String url = null;
        for (Book book : books)
        {
            url = book.getBookUrl();
            String[] split = url.split("http://book.zongheng.com/book/");   //字符串拆分，从URL中获取代码
            for (String s : split)
            {
                String[] split1 = s.split(".html");
                for (String code : split1)
                {
                    if(!code.equals(""))
                    {
                        book.setBookUrl(code);  //更新URL
                    }
                }
            }
        }

        return books;       //返回操作好的链表
    }

    public static void readChapter() throws IOException
    {
        /**
         * @function readChapter
         * @param []
         * @return void
         * @description 读入章节，每一本书放到一个表中
         * @author Liu Yuan
         * @date 2021/10/24
         */
        List<Book> books = getBookCode();           //获取书对象链表
        String Url = null;                          //存放每本书的章节URL
        Connection connection2 = null;              //写表用连接
        PreparedStatement statement2 = null;        //写表用statement
        int count_book = 0,count_chapter = 0;       //记录写入数量

        try
        {
            connection = utils.getConnection();
            connection2 = utils.getConnection();
            //进入对应文章
            for (Book book : books)
            {
                System.out.println("-------------读入第 " + ++count_book + " 本书-------------");
                Url = "http://book.zongheng.com/showchapter/"+ book.getBookUrl() +".html";              //连接章节所在网页
                Document document = Jsoup.parse(new URL(Url),10000);                        //获取文档
                Elements elements = document.getElementsByClass("chapter-list clearfix");     //获取章节元素集

                //创建表
                statement = connection.prepareStatement("create table " + book.getBookName() +" (id int primary key auto_increment,chapter varchar(100))");
                //System.out.println(statement);
                statement.executeUpdate();

                //进入对应板块
                for (Element element : elements)
                {
                    Elements chapters = element.getElementsByClass(" col-4");
                    //获取章节，插入数据
                    for (Element chapter : chapters)
                    {
                        System.out.println("读入第 " + ++count_chapter +" 条记录");
                        statement2 = connection2.prepareStatement("insert into " + book.getBookName() +" values(null,?)");
                        statement2.setString(1,chapter.text());
                        //System.out.println(statement2);
                        statement2.executeUpdate();
                    }
                    count_chapter = 0;  //清空计数
                }
                System.out.println("-------------第 " + ++count_book + " 本书读入结束-------------");
            }
        } catch (SQLException throwables)
        {
            throwables.printStackTrace();
        }
    }
}


