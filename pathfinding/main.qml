import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import Menu 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MenuModel
    {
        id: menu
    }

    ColumnLayout
    {
    spacing: 2
        RowLayout
        {
        spacing: 2
            Button
            {
                text: qsTr("Add")
                onClicked: menu.addToCounter()
            }

            Text
            {
                text: menu.counter
            }
        }
    }
}
