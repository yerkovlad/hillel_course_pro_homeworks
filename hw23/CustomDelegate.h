#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>

class CustomDelegate : public QStyledItemDelegate {
    Q_OBJECT

public:
    explicit CustomDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QStyledItemDelegate::paint(painter, option, index);

        if (index.column() == 0) {
            painter->save();

            QString text = index.data(Qt::DisplayRole).toString();
            if (text.startsWith("[DIR]")) {
                painter->setPen(Qt::blue);
            } else {
                painter->setPen(Qt::darkGreen);
            }

            painter->drawText(option.rect.adjusted(5, 0, 0, 0), Qt::AlignVCenter | Qt::AlignLeft, text);
            painter->restore();
        }
    }
};

#endif // CUSTOMDELEGATE_H