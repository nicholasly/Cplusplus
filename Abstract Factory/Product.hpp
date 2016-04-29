//
//  Product.hpp
//  polymorphic and OOP design pattern
//  Abstract Factory
//
//  Created by Nicholas.L.Y on 2016/4/25.
//  Copyright © 2016年 廖颖泓. All rights reserved.
//
class Window {
public:
    virtual ~Window() = 0;
    virtual void operation() = 0;
    virtual getToolkit() = 0;
    virtual getType() = 0;
    void deleteWindow(Window&);
protected:
    Window();

};
class ToolboxWindow : public Window {
public:
    ToolboxWindow();
    virtual void operation();
    virtual ~ToolboxWindow();
};
class LayersWindow : public Window {
public:
    LayersWindow();
    virtual void operation();
    virtual ~LayersWindow();
};
class MainWindow : public Window {
public:
    MainWindow();
    virtual void operation();
    virtual ~MainWindow();
};

