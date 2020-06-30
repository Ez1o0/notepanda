/**
 * Copyright (c) 2020 ChungZH. ALl Rights Reserved.
 * Licensed under the MIT license.
 * See file LICENSE for detail or copy at <https://opensource.org/licenses/MIT>
 *
 * This file is a part of Notepanda.
 *
 * @file mainwindow.h
 * @brief This file declares the MainWindow class.
 *        It is the main window of notepanda.
 *
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QColorDialog>
#include <QDockWidget>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPlainTextEdit>
#include <QStatusBar>
#include <QTextBrowser>
#include <QToolBar>

#include "../core/configmanager.h"
#include "../core/texteditor.h"
#include "preferenceswindow.h"

QT_BEGIN_NAMESPACE
class TextEditor;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

   public:
    MainWindow(ConfigManager *confManager, QWidget *parent = nullptr);
    ~MainWindow();
    TextEditor *plainTextEdit;

   protected:
    void closeEvent(QCloseEvent *event) override;

   private slots:
    void changeWindowTitle();
    void quit();
    void updateStatusBar();
    void normalMode(bool first);
    void stickyNoteMode();
    void documentWasModified();

   private:
    void setupUi();
    QToolBar *ToolBar;
    ConfigManager *configManager;
    PreferencesWindow *pfWindow;
    QTextBrowser *previewPanel;
    QDockWidget *DockWidget;

    /**
     * @brief currentMode
     *    0: normal mode
     *    1: sticky mode
     */
    int currentMode;
    bool isPintotop;

    // Sticky note mode

    QToolBar *SToolBar;
    QAction *changeBgColor;
    QColorDialog *ColorDialog;
    QColor currentColor;

    // UI
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionAbout;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionQuit;
    QAction *actionCut;
    QAction *actionPrint;
    QAction *actionPreferences;
    QAction *actionSticky_note_mode;
    QAction *actionNormalmode;
    QAction *actionPin_to_top;
    QAction *actionPreview_panel;
    QAction *actionReadOnlyMode;
    QMenu *menuFile;
    QMenu *menuAbout;
    QMenu *menuEdit;
    QMenu *menuView;
    QStatusBar *statusbar;
};
#endif  // MAINWINDOW_H
