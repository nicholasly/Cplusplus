//
//  Factory.hpp
//  polymorphic and OOP design pattern
//  Abstract Factory
//
//  Created by Nicholas.L.Y on 2016/4/25.
//  Copyright © 2016年 廖颖泓. All rights reserved.
//
class Window;
class UIFactory {
public:
    virtual ~UIFactory() = 0;
    virtual ToolboxWindow getToolboxWindow() = 0;
    virtual LayersWindow getLayersWindow() = 0;
    virtual MainWindow getMainWindow() = 0;
protected:
    UIFactory();
};
class MFCUIFactory : public UIFactory {
public:
    MFCUIFactory();
    ~MFCUIFactory();
    ToolboxWindow* getToolboxWindow() {
        return new ToolboxWindow();
    }
    LayersWindow* getLayersWindow() {
        return new LayersWindow();
    }
    MainWindow* getMainWindow() {
        return new MainWindow();
    }
};
class GtkUIFactory : public UIFactory {
public:
    GtkUIFactory();
    ~GtkUIFactory();
    ToolboxWindow* getToolboxWindow() {
        return new ToolboxWindow();
    }
    LayersWindow* getLayersWindow() {
        return new LayersWindow();
    }
    MainWindow* getMainWindow() {
        return new MainWindow();
    }
};
class QtUIFactory : public UIFactory {
public:
    QtUIFactory();
    ~QtUIFactory();
    ToolboxWindow* getToolboxWindow() {
        return new ToolboxWindow();
    }
    LayersWindow* getLayersWindow() {
        return new LayersWindow();
    }
    MainWindow* getMainWindow() {
        return new MainWindow();
    }
};

