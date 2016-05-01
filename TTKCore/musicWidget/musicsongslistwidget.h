#ifndef MUSICSONGSLISTWIDGET_H
#define MUSICSONGSLISTWIDGET_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2014 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QMenu>
#include <QTimer>
#include <QContextMenuEvent>
#include "musicsong.h"
#include "musicabstracttablewidget.h"

class MusicSongsListPlayWidget;
class MusicSongsListItemInfoWidget;

/*! @brief The class of the songs list widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_WIDGET_EXPORT MusicSongsListWidget : public MusicAbstractTableWidget
{
    Q_OBJECT
public:
    explicit MusicSongsListWidget(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    virtual ~MusicSongsListWidget();

    void setSongsFileName(MusicSongs *songs);
    /*!
     * Set songs file names.
     */
    void updateSongsFileName(const MusicSongs &songs);
    /*!
     * Update songs file names in table.
     */
    void clearAllItems();
    /*!
     * Clear All Items.
     */

    void selectRow(int index);
    /*!
     * Select the current play row.
     */
    inline void setPlaybackMode(MusicObject::SongPlayType type) { m_songplaymode = type;}
    /*!
     * Set current play mode.
     */
    inline void setTransparent(int transparent) { m_transparent = transparent;}
    /*!
     * Set item transparent.
     */
    void setTimerLabel(const QString &t) const;
    /*!
     * Update item time label time.
     */
    void updateCurrentArtist();
    /*!
     * Update current artist when it download finished.
     */
    void replacePlayWidgetRow();
    /*!
     * Replace current play widget row.
     */

Q_SIGNALS:
    void musicPlayOrder();
    /*!
     * Set current play mdoe to order.
     */
    void musicPlayRandom();
    /*!
     * Set current play mdoe to random.
     */
    void musicPlayListLoop();
    /*!
     * Set current play mdoe to list loop.
     */
    void musicPlayOneLoop();
    /*!
     * Set current play mdoe to single loop.
     */
    void musicPlayItemOnce();
    /*!
     * Set current play mdoe to just once.
     */
    void musicAddNewFiles();
    /*!
     * Add new music file or files to list.
     */
    void musicAddNewDir();
    /*!
     * Add new music dir to list.
     */

    void isSearchFileListEmpty(bool &empty);
    /*!
     * Check current list is searched or not.
     */
    void isCurrentIndexs(bool &state);
    /*!
     * Check is current play stack widget.
     */
    void deleteItemAt(const MIntList &index, bool fileRemove);
    /*!
     * Delete items from indexs and check remove file or not.
     */
    void getMusicIndexSwaped(int before, int after, int play, QStringList &list);
    /*!
     * Swap the current play index when user drag and drop.
     */

public Q_SLOTS:
    virtual void listCellEntered(int row, int column) override;
    /*!
     * Table widget list cell enter.
     */
    virtual void listCellClicked(int row, int column) override;
    /*!
     * Table widget list cell click.
     */
    void musicPlayClicked();
    /*!
     * Music item has double been clicked.
     */
    void setDeleteItemAt();
    /*!
     * Delete item from list at current row.
     */
    void setDeleteItemAll();
    /*!
     * Delete all items from list.
     */
    void setDeleteItemWithFile();
    /*!
     * Delete item or items from list with file.
     */
    void showTimeOut();
    /*!
     * Show play item information widget.
     */
    void stayTimeOut();
    /*!
     * Hide play item information widget.
     */
    void setChangSongName();
    /*!
     * Reset item name by current row.
     */
    void musicOpenFileDir();
    /*!
     * Open the music at local path.
     */
    void musicMakeRingWidget();
    /*!
     * Open music make ring widget.
     */
    void musicTransformWidget();
    /*!
     * Open music transform widget.
     */
    void musicFileInformation();
    /*!
     * Open music file information widget.
     */
    void setItemRenameFinished(const QString &name);
    /*!
     * Rename item artist label is finised.
     */

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void contextMenuEvent(QContextMenuEvent *event) override;
    /*!
     * Override the widget event.
     */
    void startToDrag();
    /*!
     * Start to drag to play list.
     */

    int m_transparent;
    int m_playRowIndex, m_dragStartIndex;
    QPoint m_dragStartPoint;
    bool m_mouseMoved;

    QTimer m_timerShow, m_timerStay;
    MusicSongs *m_musicSongs;
    MusicSongsListItemInfoWidget *m_musicSongsInfoWidget;
    MusicSongsListPlayWidget *m_musicSongsPlayWidget;

    bool m_leftButtonPressed;
    bool m_renameActived, m_deleteItemWithFile;
    QTableWidgetItem *m_renameItem;
    MusicObject::SongPlayType m_songplaymode;

};

#endif // MUSICSONGSLISTWIDGET_H