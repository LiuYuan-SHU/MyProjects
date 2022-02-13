package src.crawler;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.net.URL;
import java.sql.*;
import java.util.Properties;

/**
 * @author Liu Yuan
 * @create 2021-10-23-15:12
 * @describe JDBC工具类
 */
public class utils
{
    private static String url;
    private static String user;
    private static String password;
    private static String driver;

    //获取连接、用户、密码、驱动
    static
    {
        try
        {
            Properties pro = new Properties();
            try
            {
                pro.load(new FileReader("E:\\刘元\\学校\\大学\\大二\\项目\\Crawler\\Chapter\\src\\main\\java\\src\\jdbc.properties"));
            } catch (IOException e)
            {
                e.printStackTrace();
            }

            url = pro.getProperty("url");
            user = pro.getProperty("user");
            password = pro.getProperty("password");
            driver = pro.getProperty("driver");

            Class.forName(driver);
        } catch (ClassNotFoundException e)
        {
            e.printStackTrace();
        }
    }

    public static Connection getConnection() throws SQLException
    {
        /**
         * @function getConnection
         * @param []
         * @return java.sql.Connection
         * @description 获取数据库连接
         * @author Liu Yuan
         * @date 2021/10/23
         */
        return DriverManager.getConnection(url,user,password);
    }

    public static void close(Statement statement, Connection connection)
    {
        /**
         * @function close
         * @param [statement, connection]
         * @return void
         * @description 关闭连接
         * @author Liu Yuan
         * @date 2021/10/23
         */
        close(null,statement,connection);
    }

    public static void close(ResultSet resultSet,Statement statement, Connection connection)
    {
        /**
         * @function close
         * @param [resultSet, statement, connection]
         * @return void
         * @description 关闭连接
         * @author Liu Yuan
         * @date 2021/10/23
         */
        if(resultSet != null)
        {
            try
            {
                resultSet.close();
            } catch (SQLException throwables)
            {
                throwables.printStackTrace();
            }
        }
        if(statement != null)
        {
            try
            {
                statement.close();
            } catch (SQLException throwables)
            {
                throwables.printStackTrace();
            }
        }
        if(connection != null)
        {
            try
            {
                connection.close();
            } catch (SQLException throwables)
            {
                throwables.printStackTrace();
            }
        }
    }
}
