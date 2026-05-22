#pragma once
#ifdef TOOLS_ENABLED
#include <godot_cpp/classes/editor_inspector_plugin.hpp>

namespace godot {

class MrpInspectorPlugin : public EditorInspectorPlugin {
    GDCLASS(MrpInspectorPlugin, EditorInspectorPlugin)

public:
    virtual bool _can_handle(Object *p_object) const override;

protected:
    static void _bind_methods();
};

} // namespace godot
#endif
