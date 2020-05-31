# treefog-server
C++ MVC Framework TreeFog Server Project

## References
- https://www.treefrogframework.org/ja/

## Before Install

### For Ubunts

```
sudo apt-get install -y qt5-default qt5-qmake libqt5sql5-mysql libqt5sql5-psql libqt5sql5-odbc libqt5sql5-sqlite libqt5core5a libqt5qml5 libqt5xml5 qtbase5-dev qtdeclarative5-dev qtbase5-dev-tools gcc g++ make cmake
```

mysql Install
```
sudo apt install mysql-server mysql-client
```

## Build
```
# onece
qmake -r "CONFIG+=debug"

make
```

## Application Start
```
treefrog -e dev
```