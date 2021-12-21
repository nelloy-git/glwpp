#pragma once

namespace glwpp {

enum class Button {
    Left,
    Right,
    Middle,
    Button_4,
    Button_5,
    Button_6,
    Button_7,
    Button_8,
    Unknown
};

Button toButton(int glfw_button);

}