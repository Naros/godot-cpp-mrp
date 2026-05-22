#include "register_types.h"
#include "mrp_node.h"
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#ifdef TOOLS_ENABLED
#include "editor/mrp_editor_plugin.h"
#include "editor/mrp_debugger_plugin.h"
#include "editor/mrp_inspector_plugin.h"
#include <godot_cpp/classes/editor_plugin_registration.hpp>
#endif

using namespace godot;

void initialize_mrp_module(ModuleInitializationLevel p_level) {
    if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        ClassDB::register_class<MrpNode>();
    }
#ifdef TOOLS_ENABLED
    if (p_level == MODULE_INITIALIZATION_LEVEL_EDITOR) {
        ClassDB::register_class<MrpDebuggerPlugin>();
        ClassDB::register_class<MrpInspectorPlugin>();
        ClassDB::register_class<MrpEditorPlugin>();
        EditorPlugins::add_by_type<MrpEditorPlugin>();
    }
#endif
}

void uninitialize_mrp_module(ModuleInitializationLevel p_level) {
#ifdef TOOLS_ENABLED
    if (p_level == MODULE_INITIALIZATION_LEVEL_EDITOR) {
        EditorPlugins::remove_by_type<MrpEditorPlugin>();
    }
#endif
}

extern "C" {
GDExtensionBool GDE_EXPORT mrp_library_init(
        GDExtensionInterfaceGetProcAddress p_get_proc_address,
        GDExtensionClassLibraryPtr p_library,
        GDExtensionInitialization *r_initialization) {
    GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
    init_obj.register_initializer(initialize_mrp_module);
    init_obj.register_terminator(uninitialize_mrp_module);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
    return init_obj.init();
}
}
