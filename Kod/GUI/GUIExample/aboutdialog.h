#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H
#include <ui_about.h>

// Moje okno dialogowe dziedziczy po standardowym oknie dialogowym Qt
// w ten sposób dostaje wszystkie cechy tego okna
// m.in może być rozszerzane, klikalne, zamykane maksymalizowane
class AboutDialog : public QDialog, public Ui::About // ta nazwa pochodzi z about.ui
{
    Q_OBJECT

public:
    AboutDialog( QWidget * parent = 0 );
};

#endif // ABOUTDIALOG_H
