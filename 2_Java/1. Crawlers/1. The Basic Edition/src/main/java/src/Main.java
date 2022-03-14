package src;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import src.book.Book;

import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.List;

import static src.crawler.Crawler.*;

/**
 * @author Liu Yuan
 * @create 2021-10-23-15:43
 * @describe
 */
public class Main
{
    public static void main(String[] args) throws IOException
    {
        readChapter();
    }
}
