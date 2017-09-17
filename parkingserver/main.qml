/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtQuick.Window 2.0
import QtLocation 5.6
import QtPositioning 5.6

Window {
    width: 512
    height: 512
    visible: true

    Plugin {
             id: mbPlugin
             name: "osm"
             PluginParameter {
                      name: "osm.mapping.host";
                      value: "http://a.tile.openstreetmap.org/"
                  }
           }

    Map    {
            id: map

            anchors.centerIn: parent;
            anchors.fill: parent
            activeMapType: supportedMapTypes[7]
            center {
                   latitude: -27.5
                   longitude: 153.1
            }
            plugin: mbPlugin
            zoomLevel: 20
            objectName: "mainMap"

           /* MapCircle {
                id: circle1
                color: 'red'
                border.width: 1
                radius: 1.0
                center { latitude: -27.5
                        longitude: 153.1}
                objectName: "mainCircle"
            }*/

            MapQuickItem {
                id: marker
                coordinate {latitude: -27.5
                            longitude: 153.1}
                anchorPoint.x: image.width * 0.5
                anchorPoint.y: image.height

                sourceItem: Image {
                       id: image
                       height: 35
                       width: 35
                       source: "geotag.png"
                   }

            }

            MapPolyline {
                id: track
                line.width: 3
                line.color: 'green'
            }



            function recenter(lat,lng) {
                  clearMapItems();
                  //circle1.center.latitude = lat;
                  //circle1.center.longitude = lng;
                  marker.coordinate.latitude = lat;
                  marker.coordinate.longitude = lng;
                  //addMapItem(circle1);
                  addMapItem(marker);
                  map.center.latitude = lat;
                  map.center.longitude = lng;
                  map.update();
            }

            function tracking(lat, lng) {
                  map.center.latitude = lat;
                  map.center.longitude = lng;
                  track.addCoordinate(map.center);
                  track.update();
                  addMapItem(track);
                  map.update();
            }

            function clearmap() {
                  map.clearMapItems();
            }

            function zoom(val) {
                  map.zoomLevel = val;
            }

            function savemap(filename){
                  map.grabToImage(function(result) {
                                           result.saveToFile(filename);
                                       });
            }
        }
}
