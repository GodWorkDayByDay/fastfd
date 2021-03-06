#ifndef LDS_SELECTGOODS_H
#define LDS_SELECTGOODS_H

#include <QWidget>
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
#include <QtWidgets>
#else
#include <QtGui>
#endif

class QLineEdit;
class lds_menu;
class lds_selectgoods : public QWidget
{
    Q_OBJECT
public:
    explicit lds_selectgoods(QWidget *parent = 0);
    QString gettext();
    void settext(const QString & text);
private slots:
    void show_Selectgoods();
signals:
    void okstr1(const QString &text1);
private:
    QLineEdit *line;
};

#include <QDialog>
#include <QFrame>
class Ui_selectgoods_Widget;
class lds_model_sqlrelationaltablemodel;
class Selectgoods:public QDialog{
    Q_OBJECT
public:
    explicit Selectgoods(lds_menu *parent = 0);
    void setselectmultimode();
    void setitem_flag(const QChar & flag/*Y N*/);//追加 【直销商品】 属性
    void setstcheck_sheetno();//追加【盘点】属性
signals:
    void okstr(const QString &text);
    void okstr1(const QString &text1);
    void okstrs(const QStringList &texts);

private slots:
    void toselect(const QString &filter=QString());//tableview刷新

    void took();
private:
    Ui_selectgoods_Widget *ui;
    lds_model_sqlrelationaltablemodel *tablemodel;
    QString sql_select;
    QString _item_flag;
    QString _check_sheetno;
    lds_menu *_parent;
};

#endif // LDS_SELECTGOODS_H
