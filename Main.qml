import QtQuick
import QtQuick.Window

Window {
    visible: true
    width: 800
    height: 600
    title: qsTr("Power Gauge Pro Coding Challenge")

    // Iterate through frontendConfigs and configure ValueTracker instances.
    Repeater {
        model: frontendConfigs
        delegate: ValueTracker {
            uniqueId: modelData["id"]
            x: modelData["x"]
            y: modelData["y"]
            color: modelData["color"]
            dataSource: modelData["dataSource"]
        }
    }
}
