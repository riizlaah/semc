#pragma once

#include "raylib-cpp/raylib-cpp.hpp"
#include "utils.hpp"
#include <string>
#include <list>
#include <iostream>

namespace semc {

    class Node {
    private:
        Node* parent = nullptr;
    protected:
        std::list<Node*> children;
        std::string name;
    public:
        Node() : name("Node") {}
        Node(const std::string& name): name(name) {}
        virtual ~Node() {}

        virtual void _enter_tree() {}
        virtual void _exit_tree() {}
        virtual void _process(float delta) {}
        virtual void _physics_process(float delta) {}
        virtual void _destroyed() {}
        virtual std::string get_name() const { return name; }
        virtual void set_name(const std::string& new_name) { name = new_name; }

        void add_child(Node* child) {
            std::cout << "Adding child " << child->get_name() << " to parent " << get_name();
            std::flush(std::cout);
            children.push_back(child);
            child->parent = this;
            child->_enter_tree();
        }

        void remove_child(Node* child) {
            children.remove(child);
            child->_exit_tree();
            child->_destroyed();
            delete child;
        }

        void process(float delta) {
            _process(delta);
            for (Node* child : children) {
                child->process(delta);
            }
        }

        void physics_process(float delta) {
            _physics_process(delta);
            for (Node* child : children) {
                child->physics_process(delta);
            }
        }
    };

    class Window {
    private:
        RWindow window;
        Node* root = nullptr;
    public:
        Window(int width, int height, const std::string& title) : window(width, height, title.c_str()) {
            root = new Node();
            SetTargetFPS(60);
            while (!window.ShouldClose()) {
                float delta = GetFrameTime();
                window.BeginDrawing();
                window.ClearBackground(BLACK);
                root->process(delta);
                window.DrawFPS();
                window.EndDrawing();
            }
        }
        ~Window() {
            if (root) {
                delete root;
                root = nullptr;
            }
            window.Close();
        }
        Node* get_root() { return root; }
        // void start() {

        // }
    };

    class TextNode : public Node {
    private:
        std::string text;
        RColor color = RAYWHITE;
        RColor outline = RAYWHITE;
        RFont font = GetFontDefault();
        int fontSize = 20;
        int outlineSize = 0;
    public:
    TextNode(const std::string& text) : text(text) {
        
    };
    TextNode(const std::string& text, const RColor& color, int fontSize = 20, const RColor& outline = RAYWHITE, int outlineSize = 0)
        : text(text), color(color), fontSize(fontSize), outline(outline), outlineSize(outlineSize) {};
    void _process(float delta) override {
        // font.DrawText(text.c_str(), 10, 10, fontSize, color);
        // if (outlineSize > 0) {
        //     font.DrawText(text.c_str(), 10, 10, fontSize + outlineSize, outline);
        // }
    };

};
};



using SWindow = semc::Window;
using SNode = semc::Node;
using STextNode = semc::TextNode;