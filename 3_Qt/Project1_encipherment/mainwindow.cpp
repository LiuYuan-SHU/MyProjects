#include "mainwindow.h"
#include "./MD5/MD5.h"
#include "./SHA/SHA256.h"
#include "./SHA/SHA_Tools.h"
#include "./DES/DES.h"

#include <fstream>
#include <bitset>
#include <Windows.h>
#include <string>
#include <QString>
#include <QBoxLayout>
#include <QDebug>

using namespace Liuyuan;

bool MainWindow::isEmpty(QString &text)
{
    if (text.isEmpty())
    {
        this->_page_password->insertHtml(
                    "<center>"
                        "<b>"
                            "<font face=\"JetBrains Mono\" size=\"4\" color=\"red\">"
                                "Your text is empty!<br>"
                                "please input your text before click any button!<br>"
                            "</font>"
                        "</b>"
                    "</center>"
                    );
        return true;
    }
    return false;
}

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{ 
    //初始化主窗口
    this->resize(800,600);
    this->setWindowTitle("Encipherment");
    
    //初始化文本窗口
    this->_page_text = new QTextEdit();
    this->_page_password = new QTextEdit();
    this->_page_log = new QTextEdit();
    
    //初始化按钮
    //_button_MD5
    this->_button_MD5 = new QPushButton("MD5", this);
    this->_button_MD5->setFont(QFont("JetBrains Mono", 18, QFont::Black, true));
    //_button_SHA
    this->_button_SHA = new QPushButton("SHA", this);
    this->_button_SHA->setFont(QFont("JetBrains Mono", 18, QFont::Black, true));
    //_button_DES_encode
    this->_button_DES_encode = new QPushButton("DES", this);
    this->_button_DES_encode->setFont(QFont("JetBrains Mono", 18, QFont::Black, true));
    //_button_DES_decode
    //this->_button_DES_decode = new QPushButton("DES_decode", this);
    //this->_button_DES_decode->setFont(QFont("JetBrains Mono", 18, QFont::Black, true));
    //_button_AES
    //this->_button_AES = new QPushButton("AES", this);
    //this->_button_AES->setFont(QFont("JetBrains Mono", 18, QFont::Black, true));
    //_button_RSA
    //this->_button_RSA = new QPushButton("RSA", this);
    //this->_button_RSA->setFont(QFont("JetBrains Mono", 18, QFont::Black, true));
    //_button_close
    this->_button_close = new QPushButton("Close", this);
    this->_button_close->setFont(QFont("JetBrains Mono", 18, QFont::Black, true));
    
    //横向排列加密方式选择按钮
    QHBoxLayout *topButtonLayout = new QHBoxLayout();
    topButtonLayout->addWidget(this->_button_MD5);
    topButtonLayout->addWidget(this->_button_SHA);
    topButtonLayout->addWidget(this->_button_DES_encode);
    //topButtonLayout->addWidget(this->_button_AES);
    //topButtonLayout->addWidget(this->_button_RSA);
    
    //增加第二行按钮
    //QHBoxLayout *topButtonLayout2 = new QHBoxLayout();
    //topButtonLayout2->addWidget(this->_button_DES_encode);
    //topButtonLayout2->addWidget(this->_button_DES_decode);
    
    //组合按钮和明文窗口
    QVBoxLayout *topTextLayout = new QVBoxLayout();
    topTextLayout->addWidget(this->_page_text);
    topTextLayout->addLayout(topButtonLayout);
    //topTextLayout->addLayout(topButtonLayout2);
    
    //放置close按钮
    QHBoxLayout *belowButtonLayout = new QHBoxLayout();
    belowButtonLayout->addWidget(this->_button_close);
    
    //组合close按钮和密码输出窗口
    QVBoxLayout *belowTextLayout = new QVBoxLayout();
    belowTextLayout->addWidget(this->_page_password);
    belowTextLayout->addLayout(belowButtonLayout);
    
    //纵向排列好左边的界面
    QVBoxLayout *leftLayout = new QVBoxLayout();
    leftLayout->addLayout(topTextLayout);
    leftLayout->addLayout(belowTextLayout);
    
    //右边的字符界面好像有点大，调整一下宽度
    this->_page_log->setMaximumWidth(350);
    
    //横向排列好整个界面
    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addLayout(leftLayout);
    mainLayout->addWidget(this->_page_log);
    setLayout(mainLayout);
    
    //文本窗口初始化，设置占位符
    this->_page_text->setPlaceholderText("输入明文");
    this->_page_password->setPlaceholderText("打印密码");
    this->_page_password->setReadOnly(true);            //设置输出窗口为只读
    this->_page_log->setPlaceholderText("程序log");
    this->_page_log->setReadOnly(true);                 //设置log窗口为只读
    
    //连接信号与槽
    //close the program
    connect(this->_button_MD5, QPushButton::clicked, this, this->onMD5);
    connect(this->_button_SHA, QPushButton::clicked, this, this->onSHA);
    connect(this->_button_DES_encode, QPushButton::clicked, this, this->onDES_encode);
    //connect(this->_button_DES_decode, QPushButton::clicked, this, this->onDES_decode);
    //connect(this->_button_AES, QPushButton::clicked, this, this->onAES);
    //connect(this->_button_RSA, QPushButton::clicked, this, this->onRSA);
    //move the cursor to the end of text
    connect(this->_page_log, SIGNAL(textChanged()),this, SLOT(onLogTextChanged()));
    //connect close
    connect(this->_button_close, QPushButton::clicked, this, close);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onMD5()
{
    this->_page_password->clear();
    this->_page_log->insertHtml(
                "<center>"
                    "<b>"
                        "<font face=\"JetBrains Mono\" size=\"4\" color=\"blue\">"
                            "<br>---------- SLOT onMD5 ----------"
                        "</font>"
                    "</b>"
                "</center>"
                );
    QString text = this->_page_text->toPlainText();
    //protection:防止在没有任何输入的情况下点击按钮
    if(MainWindow::isEmpty(text)) 
    {
        this->_page_log->insertHtml(
                    "<center>"
                        "<b>"
                            "<font face=\"JetBrains Mono\" size=\"4\" color=\"red\">"
                                "<br>NO INPUT"
                            "</font>"
                        "</b>"
                    "</center>"
                    );
        slotEnd();
        return; 
    }
    
    static ZhouPengfei::my_md5 m;
    //将text从QString转换为char*,传给接口函数
    m.MD5(text.toLocal8Bit());
    this->_page_log->setTextColor(QColorConstants::Black);
    //输出结果
    this->_page_password->insertHtml(
                    "<b>"
                        "<font face=\"JetBrains Mono\" size=\"4\" color=\"black\">"
                            "Your digest:"
                        "</font>"
                    "</b>"
                );
    this->_page_password->insertHtml(
                        "<font face=\"JetBrains Mono\" size=\"4\" color=\"black\">"
                            "<br>"
                        "</font>"
                );
    for(int i = 0; i <= 3; i++)
    {
        this->_page_password->insertPlainText(QString::number(m.get_lGroup()[i],16).toUpper());
    }
    this->_page_log->insertPlainText("\n");
    this->_page_log->insertPlainText("onMD5 return");
    this->slotEnd();
}

void MainWindow::onSHA()
{
    this->_page_password->clear();
    this->_page_log->insertHtml(
                "<center>"
                    "<b>"
                        "<font face=\"JetBrains Mono\" size=\"4\" color=\"blue\">"
                            "<br>---------- SLOT onSHA ----------<br>"
                        "</font>"
                    "</b>"
                "</center>"
                );
    
    //protection
    QString text = this->_page_text->toPlainText();
    if(MainWindow::isEmpty(text)) 
    {
        this->_page_log->insertHtml(
                    "<center>"
                        "<b>"
                            "<font face=\"JetBrains Mono\" size=\"4\" color=\"red\">"
                                "NO INPUT"
                            "</font>"
                        "</b>"
                    "</center>"
                    );
        slotEnd();
        return; 
    }
    if(text.length() >= 1000) 
    {
        this->_page_password->insertHtml(
                    "<center>"
                        "<b>"
                            "<font face=\"JetBrains Mono\" size=\"4\" color=\"red\">"
                                "Your text is too long (longer than 1000)!<br>"
                            "</font>"
                        "</b>"
                    "</center>"
                    );
        this->_page_log->insertHtml(
                    "<center>"
                        "<b>"
                            "<font face=\"JetBrains Mono\" size=\"4\" color=\"black\">"
                                "Input is too long, return<br>"
                            "</font>"
                        "</b>"
                    "</center>"
                    );
        slotEnd();
        return;
    }
    
    XvJianchao::PAD((unsigned char*)text.toLocal8Bit().toUpper().data());
    XvJianchao::M_D = XvJianchao::sha256.DEAL(XvJianchao::M);
    this->_page_password->setTextColor(QColorConstants::Black);
    this->_page_password->insertHtml(
                    "<b>"
                        "<font face=\"JetBrains Mono\" size=\"4\" color=\"black\">"
                            "Your digest:"
                        "</font>"
                    "</b>"
                );
    this->_page_password->insertHtml(
                        "<font face=\"JetBrains Mono\" size=\"4\" color=\"black\">"
                            "<br>"
                        "</font>"
                );
    for(int i = 0; i < 8; i++) { this->_page_password->insertPlainText(QString::number(XvJianchao::M_D.H[i]).toUpper()); }
    this->_page_log->setTextColor(QColorConstants::Black);
    this->_page_log->insertPlainText("onSHA return");
    this->slotEnd();
}

void MainWindow::onDES_encode()
{
    using namespace ZhouPengfei;
    this->_page_password->clear();
    this->_page_log->insertHtml(
                "<center>"
                    "<b>"
                        "<font face=\"JetBrains Mono\" size=\"4\" color=\"blue\">"
                            "<br>---------- SLOT onDES ----------<br>"
                        "</font>"
                        "<font face=\"JetBrains Mono\" size=\"4\" color=\"black\">"
                            "Input your plaintext and secret key in two lines"
                        "</font>"
                    "</b>"
                "</center>"
                );
    //protection
    QString text = this->_page_text->toPlainText();
    if(MainWindow::isEmpty(text)) 
    {
        this->_page_log->insertHtml(
                    "<center>"
                        "<b>"
                            "<font face=\"JetBrains Mono\" size=\"4\" color=\"red\">"
                                "<br>NO INPUT"
                            "</font>"
                        "</b>"
                    "</center>"
                    );
        slotEnd();
        return; 
    }
    
    //获取文本框中的内容
    QStringList text_split = text.split('\n');
    //protection: 输入内容不足两行或超过两行
    if(text_split.length() != 2)
    {
        this->_page_password->insertHtml(
                    "<center>"
                        "<b>"
                            "<font face=\"JetBrains Mono\" size=\"4\" color=\"red\">"
                                "---------- ILLEGAL INPUT ----------<br>"
                            "</font>"
                        "</b>"
                    "</center>"
                    );
        return;
    }
    //字符串分割，将第一行保存为明文，第二行保存为密钥
    QString text_plain = text_split[0];
    QString text_secret = text_split[1]; 
    
    size_t length_temp = 0;                 //遍历text_plain
    bitset<64> cipher[1024];                //存储密文，每个元素只存储64bit
    size_t length_cipher = 0;               //记录密文元素个数
    
    //打印加密结果
    this->_page_password->insertPlainText("After encoding, the result is:\n");
    while(length_temp < text_plain.size())
    {
        QString temp;
        //保存8个字符到temp中
        for(int i = 0; i < 8 && length_temp < text_plain.size(); i++)
        {
            //qDebug() << length_temp;
            temp.push_back(text_plain[length_temp++]);
        }
        //将temp转换为bitset，然后保存给plain
        bitset<64> plain = charToBitset(G2U(temp.toUtf8().data()));
        //加密plain，保存到cipher中
        cipher[length_cipher] = encrypt(plain);
        //输入这个元素
        this->_page_password->insertPlainText(bitsetToQString(cipher[length_cipher]));
        //cipher元素个数+1
        length_cipher++;
    }
    this->_page_password->insertPlainText("\n");
    
    //打印解密结果
    this->_page_password->insertPlainText("After decoding, the result is:\n");
    //为了防止最后一个字符串不满8个字符而输出额外的字符，计算所有字符个数
    const size_t length_outputCountMax = text_plain.size() * 8;
    //计算当前输入的字符个数
    size_t length_outputCount = 0;
    for(int i = 0; i < length_cipher; i++)
    {            
        qDebug() << "length_outputCount: " << length_outputCount;
        qDebug() << "length_outputCountMax: " << length_outputCountMax;
        //如果到了最后一个字符串，并且字符串的原始长度不足8个字符
        if(length_outputCount + 64 > length_outputCountMax)
        {
            QString temp = bitsetToQString(decrypt(cipher[i]));
            qDebug() << "temp: " << temp << Qt::endl;
            //qDebug() << length_outputCount;
            //qDebug() << length_outputCountMax;
            qDebug() << "length_outputCount + 8 - length_outputCountMax: " << ((length_outputCountMax - length_outputCount) / 8);
            qDebug() << "count: " << (length_outputCount + 8 - length_outputCountMax);
            for(int j = 0; j < (length_outputCountMax - length_outputCount) / 8; j++)
            {
                this->_page_password->insertPlainText(temp[j]);
            }
        }
        //正常打印
        else
        {
            this->_page_password->insertPlainText(bitsetToQString(decrypt(cipher[i])));
            length_outputCount += 64;
        }
    }
    qDebug() << "------------------------" << Qt::endl << Qt::endl;
    this->_page_password->insertPlainText("\n");
    
    //old version, only handle 8 chars
    /*
    //bitset<64> plain = charToBitset(G2U(text_plain.toUtf8().data()));
    //bitset<64> cipher = encrypt(plain);
    ////DES加密
    //this->_page_password->insertPlainText("After encoding, the result is: " + 
    //                                      bitsetToQString(cipher)  +
    //                                      //QString::fromStdString(cipher.to_string()) +
    //                                      '\n');
    ////DES解密
    //this->_page_password->insertPlainText("After decoding, the result is: " +
    //                                      bitsetToQString(decrypt(cipher)) +
    //                                      //QString::fromStdString(decrypt(cipher).to_string()) +
    //                                      '\n');
    */
    //打印结束虚线
    this->slotEnd();
}

//void MainWindow::onDES_decode()
/*
void MainWindow::onDES_decode()
{
    this->_page_password->clear();
    this->_page_log->insertHtml(
                "<center>"
                    "<b>"
                        "<font face=\"JetBrains Mono\" size=\"4\" color=\"blue\">"
                            "<br>SLOT<br>---------- onDES_decode ----------<br>"
                        "</font>"
                    "</b>"
                "</center>"
                );
}
*/

void MainWindow::onAES()
{
    this->_page_password->clear();
    this->_page_log->insertHtml(
                "<center>"
                    "<b>"
                        "<font face=\"JetBrains Mono\" size=\"4\" color=\"blue\">"
                            "<br>---------- SLOT onAES ----------<br>"
                        "</font>"
                    "</b>"
                "</center>"
                );
    this->slotEnd();
}

void MainWindow::onRSA()
{
    this->_page_password->clear();
    this->_page_log->insertHtml(
                "<center>"
                    "<b>"
                        "<font face=\"JetBrains Mono\" size=\"4\" color=\"blue\">"
                            "<br>---------- SLOT onRSA ----------<br>"
                        "</font>"
                    "</b>"
                "</center>"
                );
    this->slotEnd();
}

void MainWindow::onLogTextChanged()
{
    this->_page_log->moveCursor(QTextCursor::End);
}

void MainWindow::slotEnd()
{
    this->_page_log->insertHtml(
                "<center>"
                    "<b>"
                        "<font face=\"JetBrains Mono\" size=\"4\" color=\"blue\">"
                            "<br>--------------------------------<br>"
                        "</font>"
                    "</b>"
                "</center>"
                );
}

template<size_t N>
QString MainWindow::bitsetToQString(bitset<N> bits) 
{
    //保护
    static_assert(N % CHAR_BIT == 0, L"bitset size must be multiple of char");
    string temp;
    for (size_t j = 0; j < N / CHAR_BIT; ++j)
    {
        char next = 0;
        for (size_t i = 0; i < CHAR_BIT; ++i)
        {
            size_t index = N - (CHAR_BIT * j) - i - 1;
            size_t pos = CHAR_BIT - i - 1;
            if (bits[index])
                next |= (1 << pos);
         }
        temp.push_back(next);
    }
    //结果为倒序，因此再次颠倒 
    QString toReturn;
    for(int i = temp.size() - 1; i >= 0 ; i--)
    {
        toReturn.push_back(temp[i]);
        //qDebug() << temp[i];
    }
    //qDebug() << toReturn;
    return toReturn;
}

