#include <QApplication>
#include <QTreeView>
#include "CustomFileSystemModel.h"
#include "CustomDelegate.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CustomFileSystemModel *model = new CustomFileSystemModel;
    model->setRootPath(QDir::homePath());
    model->setFilter(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs);
    model->setNameFilters(QStringList() << "*.txt" << "*.cpp");
    model->setNameFilterDisables(false);

    QTreeView *treeView = new QTreeView;
    treeView->setModel(model);
    treeView->setRootIndex(model->index(QDir::homePath()));
    treeView->resize(800, 600);

    CustomDelegate *delegate = new CustomDelegate(treeView);
    treeView->setItemDelegate(delegate);

    treeView->show();

    return app.exec();
}