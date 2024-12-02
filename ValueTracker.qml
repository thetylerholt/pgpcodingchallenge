import QtQuick

Rectangle {
    id: valueTracker
    width: 200
    height: 100
    color: color

    property string uniqueId: ""
    property real val: 0
    property string dataSource: "N/A"
    property var dataSourceObj: null

    // Display the uniqueId and val
    Text {
        anchors.centerIn: parent
        text: uniqueId + ": " + val + ", " + dataSource
        color: "black"
        font.pointSize: 18
        font.bold: true
    }

    // Use lookup function to find the SignalEmitter object with the dataSource name
    Component.onCompleted: {
        dataSourceObj = propertyLookup.getContextProperty(dataSource);
    }

    // Connect to SignalEmitter object to listen for signals to update val.
    Connections {
        target: dataSourceObj
        function onValChanged(newValue) {
            updateVal(newValue);
        }
    }

    function updateVal(newValue) {
        val = newValue;
    }
}
