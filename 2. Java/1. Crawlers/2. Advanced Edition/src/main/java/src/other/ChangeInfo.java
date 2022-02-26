package src.other;

import src.crawler.Utils;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * @author Liu Yuan
 * @create 2022-02-26-14:21
 * @describe
 */
public class ChangeInfo
{
    static Connection connection;
    static String sql_query1;
    static String sql_query2;
    static String sql_update;
    static PreparedStatement statement_query1;
    static PreparedStatement statement_query2;
    static PreparedStatement statement_update;

    static
    {
        try
        {
            connection = Utils.getConnection();
        } catch (SQLException e)
        {
            e.printStackTrace();
        }
    }

    public static void change_collegeInfo_to_schoolID() throws SQLException
    {
        sql_query1 = "select * from csky.school";
        sql_query2 = "select * from csky.cs";
        sql_update = "update csky.cs set collegename = ? where collegename = ?";
        String school_id = "";
        String query_collegeName = "";
        try
        {
            statement_query1 = connection.prepareStatement(sql_query1, ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            statement_query2 = connection.prepareStatement(sql_query2);
        } catch (SQLException e)
        {
            e.printStackTrace();
        }
        ResultSet resultSet_school = statement_query1.executeQuery();
        ResultSet resultSet_cs = statement_query2.executeQuery();

        while (resultSet_cs.next())
        {
            query_collegeName = resultSet_cs.getString(3);
            //System.out.println(query_collegeName);
            while (resultSet_school.next())
                if (query_collegeName.equals(resultSet_school.getString(2)))
                {
                    school_id = String.valueOf(resultSet_school.getInt(1));
                    //System.out.println(school_id);
                    resultSet_school.beforeFirst();
                    break;
                }
            statement_update = connection.prepareStatement(sql_update);
            statement_update.setString(2, query_collegeName);
            statement_update.setString(1, school_id);
            System.out.println(statement_update);
            statement_update.executeUpdate();
        }

    }
}
