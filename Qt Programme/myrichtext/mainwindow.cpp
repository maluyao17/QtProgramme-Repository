#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextFrame>
#include<QDebug>
#include<QImage>
#include<QLineEdit>
#include<QPushButton>
#include<QVBoxLayout>
#include<QDialog>
#include"mysyntaxhighlighter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //获取文档对象
    QTextDocument *document=ui->textEdit->document();
    //获取根框架
    QTextFrame *rootframe=document->rootFrame();
    //创建框架格式
    QTextFrameFormat format;
    //边界颜色
    format.setBorderBrush(Qt::red);
    //边界宽度
    format.setBorder(3);
    //框架使用格式
    rootframe->setFrameFormat(format);

    QTextFrameFormat frameFormat;
    frameFormat.setBackground(Qt::lightGray);
    //设置边距
    frameFormat.setMargin(10);
    //设置填衬
    frameFormat.setPadding(5);
    frameFormat.setBorder(2);
    //设置边框样式
    frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dotted);

    //获取光标
    QTextCursor cursor=ui->textEdit->textCursor();
    //在光标处插入框架
    cursor.insertFrame(frameFormat);

    QAction *action_textFrame=new QAction(tr("框架"),this);
    connect(action_textFrame,&QAction::triggered,this,&MainWindow::showTextFrame);
    //在工具栏添加动作
    ui->mainToolBar->addAction(action_textFrame);

    QAction *action_font=new QAction(tr("字体"),this);
    //设置动作可被选中
    action_font->setCheckable(true);
    connect(action_font,&QAction::toggled,this,&MainWindow::setTextFont);
    ui->mainToolBar->addAction(action_font);

    QAction *action_textTable=new QAction(tr("表格"),this);
    QAction *action_textList=new QAction(tr("列表"),this);
    QAction *action_textImage=new QAction(tr("图片"),this);

    connect(action_textTable,&QAction::triggered,this,&MainWindow::insertTable);
    connect(action_textList,&QAction::triggered,this,&MainWindow::insertList);
    connect(action_textImage,&QAction::triggered,this,&MainWindow::insertImage);

    ui->mainToolBar->addAction(action_textTable);
    ui->mainToolBar->addAction(action_textList);
    ui->mainToolBar->addAction(action_textImage);

    QAction *action_textFind=new QAction(tr("查找"),this);
    connect(action_textFind,&QAction::triggered,this,&MainWindow::textFind);
    ui->mainToolBar->addAction(action_textFind);

    //创建对话框
    findDialog=new QDialog(this);
    //创建行编辑器
    lineEdit=new QLineEdit(findDialog);
    //创建按钮
    QPushButton *btn=new QPushButton(findDialog);
    btn->setText(tr("查找下一个"));
    connect(btn,&QPushButton::clicked,this,&MainWindow::findNext);
    //创建垂直布局管理器
    QVBoxLayout *layout=new QVBoxLayout;
    //添加部件
    layout->addWidget(lineEdit);
    layout->addWidget(btn);
    //使用布局管理器
    findDialog->setLayout(layout);

    highlighter=new MySyntaxHighlighter(ui->textEdit->document());
    ui->textEdit->append(tr("<h1><font color=red>使用HTML</font></h1>"));
}

void MainWindow::showTextFrame()
{
    QTextDocument *document=ui->textEdit->document();
    //获取第一个文本块
    QTextBlock block=document->firstBlock();
    for(int i=0;i<document->blockCount();i++)
    {
        qDebug()<<tr("文本块%1,文本框首行号为:%2,长度为%3,内容为:").arg(i).arg(block.firstLineNumber()).arg(block.length())<<block.text();
        block=block.next();
    }
}

void MainWindow::setTextFont(bool checked)
{
    if(checked)
    {
        //获取光标
        QTextCursor cursor=ui->textEdit->textCursor();
        //文本块格式
        QTextBlockFormat blockFormat;
        //水平居中
        blockFormat.setAlignment(Qt::AlignCenter);
        //字符格式
        QTextCharFormat charFormat;
        //背景色
        charFormat.setBackground(Qt::lightGray);
        //字体颜色
        charFormat.setForeground(Qt::blue);
        //字体格式
        charFormat.setFont(QFont(tr("宋体"),12,QFont::Bold,true));
        //使用下划线
        charFormat.setFontUnderline(true);
        //使用字符格式
        cursor.setCharFormat(charFormat);
        //插入文本
        cursor.insertText(tr("测试字体"));
    }
    else
    {

    }
}

void MainWindow::insertTable()
{
    QTextCursor cursor=ui->textEdit->textCursor();
    //表格格式
    QTextTableFormat format;
    //表格外边白
    format.setCellSpacing(2);
    //表格内边白
    format.setCellPadding(10);
    //插入2行2列的表格
    cursor.insertTable(2,2,format);
}

void MainWindow::insertList()
{
    //列表格式
    QTextListFormat format;
    //数字编号
    format.setStyle(QTextListFormat::ListDecimal);
    ui->textEdit->textCursor().insertList(format);
}

void MainWindow::insertImage()
{
    //图片格式
    QTextImageFormat format;
    format.setName("...");
    ui->textEdit->textCursor().insertImage(format);
}

//查找文本
void MainWindow::textFind()
{
    findDialog->show();
}

//查找下一个
void MainWindow::findNext()
{
    QString string=lineEdit->text();
    //使用查找函数查找指定字符串，查找方式为向后查找
    bool isfind=ui->textEdit->find(string,QTextDocument::FindBackward);
    //如果查找成功，输出字符串所在行和列的编号
    if(isfind)
    {
        qDebug()<<tr("行号:%1列号:%2")
                  .arg(ui->textEdit->textCursor().blockNumber())
                  .arg(ui->textEdit->textCursor().columnNumber());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
