import QtQuick 2.4

import HudControl 1.0;

HudForm {

    id: form

    ggeRpm.formatValue: function (value) {
        return value.toFixed(0)
    }

    Component.onCompleted: {
        control.start()
    }

    HudControl {
        id: control

        onVehicleChanged: function(vehicle){
            form.vehicle = vehicle
        }

    }

}
