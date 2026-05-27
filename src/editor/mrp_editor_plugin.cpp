#include "mrp_editor_plugin.h"
#ifdef TOOLS_ENABLED
#include <godot_cpp/classes/engine.hpp>

namespace godot {

String MrpEditorPlugin::_get_plugin_name() const {
    return "MRP";
}

void MrpEditorPlugin::_enter_tree() {
    for (const String& singleton_class : Engine::get_singleton()->get_singleton_list()) {
        if (!named_globals.has(singleton_class)) {
            named_globals[singleton_class] = Engine::get_singleton()->get_singleton(singleton_class);
        }
    }
}

void MrpEditorPlugin::_exit_tree() {

}

void MrpEditorPlugin::_bind_methods() {}

} // namespace godot
#endif
