import QtQuick 2.15
import QtQuick.Controls 2.15
import CustomFileViewer 1.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Custom File Viewer in QML"

    CustomFileSystemModel {
        id: fileModel
        rootPath: "C:/"
        nameFilters: ["*.cpp", "*.h"]
    }

    TreeView {
        anchors.fill: parent
        model: fileModel

        TableViewColumn {
            title: "Name"
            role: "display"
            width: 400
        }
        TableViewColumn {
            title: "Size (KB)"
            role: "size"
            width: 150
        }

        delegate: Item {
            width: parent.width
            height: 40

            Row {
                spacing: 10
                anchors.verticalCenter: parent.verticalCenter

                Rectangle {
                    width: 10
                    height: 10
                    color: model.isDir ? "blue" : "green"
                }

                Text {
                    text: model.display
                    font.bold: model.isDir
                }

                Text {
                    text: model.isDir ? "" : "(" + model.size + " KB)"
                    color: "gray"
                }
            }
        }
    }
}
