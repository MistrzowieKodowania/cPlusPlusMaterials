#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H
#include <ui_about.h>

class AboutDialog : public QDialog, public Ui::About
{
    Q_OBJECT

public:
    AboutDialog( QWidget * parent = 0 );
};

#endif // ABOUTDIALOG_H
