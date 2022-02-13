package src.book;

/**
 * @author Liu Yuan
 * @create 2021-10-23-19:46
 * @describe
 */
public class Book
{
    String bookName;                        //存储书名
    String bookUrl;                         //存储URL
    String author;                          //作者
    String style;                           //分类
    Boolean finished ;                      //是否完结
    String updateTime;                      //更新时间
    String bookIntro ;                      //存储介绍

    public Book(String bookName, String bookUrl, String author, String style, Boolean finished, String updateTime, String bookIntro)
    {
        this.bookName = bookName;
        this.bookUrl = bookUrl;
        this.author = author;
        this.style = style;
        this.finished = finished;
        this.updateTime = updateTime;
        this.bookIntro = bookIntro;
    }

    public Book()
    {
    }

    public String getBookName()
    {
        return bookName;
    }

    public void setBookName(String bookName)
    {
        this.bookName = bookName;
    }

    public String getBookUrl()
    {
        return bookUrl;
    }

    public void setBookUrl(String bookUrl)
    {
        this.bookUrl = bookUrl;
    }

    public String getAuthor()
    {
        return author;
    }

    public void setAuthor(String author)
    {
        this.author = author;
    }

    public String getStyle()
    {
        return style;
    }

    public void setStyle(String style)
    {
        this.style = style;
    }

    public Boolean getFinished()
    {
        return finished;
    }

    public void setFinished(Boolean finished)
    {
        this.finished = finished;
    }

    public String getUpdateTime()
    {
        return updateTime;
    }

    public void setUpdateTime(String updateTime)
    {
        this.updateTime = updateTime;
    }

    public String getBookIntro()
    {
        return bookIntro;
    }

    public void setBookIntro(String bookIntro)
    {
        this.bookIntro = bookIntro;
    }

    @Override
    public String toString()
    {
        return "Book{" +
                "bookName='" + bookName + '\'' +
                ", bookUrl='" + bookUrl + '\'' +
                ", author='" + author + '\'' +
                ", style='" + style + '\'' +
                ", finished=" + finished +
                ", updateTime='" + updateTime + '\'' +
                ", bookIntro='" + bookIntro + '\'' +
                '}';
    }
}
