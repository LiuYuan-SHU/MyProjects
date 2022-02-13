package src;

import src.crawler.CS;

import java.io.IOException;

/**
 * @author Liu Yuan
 * @create 2022-01-08-12:57
 * @describe
 */
public class Main
{
    public static void main(String[] args) throws IOException
    {
//        new getSchoolID().readID();                           //获取学校的基本信息：学校名称和id
//        src.crawler.getTeacherInfo.getTeacher();              //获取学校的教师信息
//        src.crawler.getTeacherInfo.insertTeacher_Basic();     //写入教师的基本信息
//        src.crawler.SchoolOperating.getRecruitment();         //写入学校招生信息
//        src.crawler.ArticleOperating.getArticles();           //写入学校文章信息
//        src.crawler.CS.getSchoolID_Name();
//        src.crawler.CS.getCSInfo();
//        src.crawler.CS.fileRead();
//        CS.writeInformation();
        CS.setSchoolID();
    }
}
