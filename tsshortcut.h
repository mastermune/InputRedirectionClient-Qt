#ifndef TSSHORTCUT_H
#define TSSHORTCUT_H
#include "global.h"
#include <QListView>
#include <QList>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QComboBox>
#include <QColorDialog>

class TsShortcut : public QWidget
{
public:
    TsShortcut(QWidget *parent = nullptr);

    void setCurrentPos(QPoint pos);
    void updateTitleText();
    void showEvent(QShowEvent * event);
    void loadNewShortcuts(void);

private:
    QString       wTitle;
    QVBoxLayout  *layout;
    QFormLayout  *formLayout;
    QListWidget  *lstWidget;
    QLabel       *lblDirections;
    QPushButton  *btnColorDialog, *btnCreateShort,
    *btnDelShort, *btnHelp, *btnPressNow;
    QLineEdit*    txtShortName;
    QPoint        curPos;
    QComboBox*    cboxBtns;
    QColor        curColor;

    QComboBox* populateItems();

    void instantiateWidgets();
    void addWidgetsToLayout();
    void connectEvents();
    void connectColorButtonEvent();
    void connectCreateButtonEvent();
    void connectDeleteButtonEvent();
    void connectPressButtonEvent();
    void connectHelpButtonEvent();
    void connectNameChangeEvent();
    void connectButtonChangeEvent();
    void connectSelectedChangeEvent();
    void saveShortcut(uint i);
    QListWidgetItem * createShortcutListItem(ShortCut newShortCut);
};

#endif // TSSHORTCUT_H
