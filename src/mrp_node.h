#pragma once
#include <godot_cpp/classes/node.hpp>

namespace godot {

class MrpNode : public Node {
    GDCLASS(MrpNode, Node)

protected:
    static void _bind_methods();
};

} // namespace godot
