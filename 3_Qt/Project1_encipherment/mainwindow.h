#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <bitset>
#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QDialog>

namespace Liuyuan
{
    class MainWindow : public QDialog
    {
        Q_OBJECT
        
    private:
        //三个文字窗口定义
        QTextEdit* _page_text;      //用户输入
        QTextEdit* _page_password;  //程序运行结果展示
        QTextEdit* _page_log;
        
        QPushButton* _button_MD5;
        QPushButton* _button_SHA;
        QPushButton* _button_DES_encode;
        //QPushButton* _button_DES_decode;
        QPushButton* _button_AES;
        QPushButton* _button_RSA;
        QPushButton* _button_close;
        
        bool isEmpty(QString& text);
        
    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        
        //tool functions
        void slotEnd();
        //将bitset转换为QString
        template<size_t N>
        QString bitsetToQString(std::bitset<N> input);
        
    //signals:
    //    void MD5();
    //    void SHA();
    //    void DES();
    //    void AES();
    //    void RSA();
        
    public slots:
        void onMD5();
        void onSHA();
        void onDES_encode();
        //void onDES_decode();
        void onAES();
        void onRSA();
        void onLogTextChanged();
    };
}
    
#endif // MAINWINDOW_H
