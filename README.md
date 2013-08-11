A plasmoid that shows IPv4 addresses in huge text

Prereqs
=======

    sudo apt-get install kdelibs5-dev

Build and Install
=================

    cd ip-monitor-kde-plasmoid/
    mkdir build && cd build
    cmake -DCMAKE_INSTALL_PREFIX=/usr .. && make
    sudo make install
    kbuildsycoca4
    kquitapp plasma-desktop
    plasma-desktop

AUTHOR
======

Original
--------
Name: Viranch Mehta
Email: viranch.mehta@gmail.com

Modified
--------
Name: Peak Xu
Email: peak.xu@gmail.com
