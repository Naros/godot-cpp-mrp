#include "mrp_editor_plugin.h"
#ifdef TOOLS_ENABLED

namespace godot {

String MrpEditorPlugin::_get_plugin_name() const {
    return "MRP";
}

void MrpEditorPlugin::_enter_tree() {
    _debugger_plugin.instantiate();
    add_debugger_plugin(_debugger_plugin);
}

void MrpEditorPlugin::_exit_tree() {
    //remove_debugger_plugin(_debugger_plugin);
    _debugger_plugin.unref();
}

void MrpEditorPlugin::_bind_methods() {}

} // namespace godot
#endif
