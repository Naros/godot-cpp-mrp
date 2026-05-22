#pragma once
#ifdef TOOLS_ENABLED
#include <godot_cpp/classes/editor_plugin.hpp>
#include "mrp_debugger_plugin.h"

namespace godot {

class MrpEditorPlugin : public EditorPlugin {
    GDCLASS(MrpEditorPlugin, EditorPlugin)

    Ref<MrpDebuggerPlugin> _debugger_plugin;

public:
    virtual String _get_plugin_name() const override;
    virtual void _enter_tree() override;
    virtual void _exit_tree() override;

protected:
    static void _bind_methods();
};

} // namespace godot
#endif
