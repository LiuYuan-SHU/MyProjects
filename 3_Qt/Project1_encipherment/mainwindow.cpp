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
        this->_page_log->insertHtml(
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
    //init main window
    this->resize(800,600);
    this->setWindowTitle("Encipherment");
    
    //init text windows
    this->_page_text = new QTextEdit();
    this->_page_password = new QTextEdit();
    this->_page_log = new QTextEdit();
    
    //init buttons
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
    this->_button_RSA = new QPushButton("RSA", this);
    this->_button_RSA->setFont(QFont("JetBrains Mono", 18, QFont::Black, true));
    //_button_close
    this->_button_close = new QPushButton("Close", this);
    this->_button_close->setFont(QFont("JetBrains Mono", 18, QFont::Black, true));
    
    //横向排列加密方式选择按钮
    QHBoxLayout *topButtonLayout = new QHBoxLayout();
    topButtonLayout->addWidget(this->_button_MD5);
    topButtonLayout->addWidget(this->_button_SHA);
    topButtonLayout->addWidget(this->_button_DES_encode);
    //topButtonLayout->addWidget(this->_button_AES);
    topButtonLayout->addWidget(this->_button_RSA);
    
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
    
    //page init
    this->_page_text->setPlaceholderText("输入明文");
    this->_page_password->setPlaceholderText("打印密码");
    this->_page_password->setReadOnly(true);
    this->_page_log->setPlaceholderText("程序log");
    this->_page_log->setReadOnly(true);
    
    //connect
    //close the program
    connect(this->_button_MD5, QPushButton::clicked, this, this->onMD5);
    connect(this->_button_SHA, QPushButton::clicked, this, this->onSHA);
    connect(this->_button_DES_encode, QPushButton::clicked, this, this->onDES_encode);
    //connect(this->_button_DES_decode, QPushButton::clicked, this, this->onDES_decode);
    //connect(this->_button_AES, QPushButton::clicked, this, this->onAES);
    connect(this->_button_RSA, QPushButton::clicked, this, this->onRSA);
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
                            "<br>---------- SLOT onMD5 ----------<br>"
                        "</font>"
                    "</b>"
                "</center>"
                );
    QString text = this->_page_text->toPlainText();
    if(MainWindow::isEmpty(text)) { return; }
    
    static ZhouPengfei::my_md5 m;
    //将text从QString转换为char*,传给接口函数
    m.MD5(text.toLocal8Bit());
    this->_page_log->setTextColor(QColorConstants::Black);
    this->_page_log->insertPlainText(QString("Your digest: "));
    for(int i = 0; i <= 3; i++)
    {
        this->_page_log->insertPlainText(QString::number(m.get_lGroup()[i],16).toUpper());
    }
    this->_page_log->insertPlainText("\n");
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
    
    QString text = this->_page_text->toPlainText();
    if(MainWindow::isEmpty(text)) { return; }
    if(text.length() >= 1000) 
    {
        this->_page_log->insertHtml(
                    "<center>"
                        "<b>"
                            "<font face=\"JetBrains Mono\" size=\"4\" color=\"red\">"
                                "Your text is too long (longer than 1000)!<br>"
                            "</font>"
                        "</b>"
                    "</center>"
                    );
        return;
    }
    
    XvJianchao::PAD((unsigned char*)text.toLocal8Bit().toUpper().data());
    XvJianchao::M_D = XvJianchao::sha256.DEAL(XvJianchao::M);
    this->_page_log->setTextColor(QColorConstants::Black);
    this->_page_log->insertPlainText("Your Digest:");
    for(int i = 0; i < 8; i++) { this->_page_log->insertPlainText(QString::number(XvJianchao::M_D.H[i]).toUpper()); }
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
                            "Input your plaintext and secret key in two lines<br>"
                        "</font>"
                    "</b>"
                "</center>"
                );
    QString text = this->_page_text->toPlainText();
    if(MainWindow::isEmpty(text)) { return; }
    
    QStringList text_split = text.split('\n');
    if(text_split.length() < 2 || text_split.length() > 2)
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
    QString text_plain = text_split[0];
    QString text_secret = text_split[1]; 
    
    size_t length_temp = 0;
    bitset<64> cipher[1024];
    size_t length_cipher = 0;
    
    this->_page_password->insertPlainText("After encoding, the result is:\n");
    while(length_temp < text_plain.size())
    {
        QString temp;
        for(int i = 0; i < 8 && length_temp < text_plain.size(); i++)
        {
            //qDebug() << length_temp;
            temp.push_back(text_plain[length_temp++]);
        }
        bitset<64> plain = charToBitset(G2U(temp.toUtf8().data()));
        cipher[length_cipher] = encrypt(plain);
        this->_page_password->insertPlainText(bitsetToQString(cipher[length_cipher]));
        length_cipher++;
    }
    this->_page_password->insertPlainText("\n");
    
    this->_page_password->insertPlainText("After decoding, the result is:\n");
    const size_t length_outputCountMax = text_plain.size() * 8;
    size_t length_outputCount = 0;
    for(int i = 0; i < length_cipher; i++)
    {            
        qDebug() << "length_outputCount: " << length_outputCount;
        qDebug() << "length_outputCountMax: " << length_outputCountMax;
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
        else
        {
            this->_page_password->insertPlainText(bitsetToQString(decrypt(cipher[i])));
            length_outputCount += 64;
        }
    }
    qDebug() << "------------------------" << Qt::endl << Qt::endl;
    this->_page_password->insertPlainText("\n");
    
    //old version, only handle 8 chars
    /************************************************************/
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
    //打印结束虚线
    this->slotEnd();
}

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
                            "--------------------------------<br>"
                        "</font>"
                    "</b>"
                "</center>"
                );
}

template<size_t N>
QString MainWindow::bitsetToQString(bitset<N> bits) 
{
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
    QString toReturn;
    for(int i = temp.size() - 1; i >= 0 ; i--)
    {
        toReturn.push_back(temp[i]);
        //qDebug() << temp[i];
    }
    //qDebug() << toReturn;
    return toReturn;
}

