#include "mrp_inspector_plugin.h"
#ifdef TOOLS_ENABLED

namespace godot {

bool MrpInspectorPlugin::_can_handle(Object *p_object) const {
    return false;
}

void MrpInspectorPlugin::_bind_methods() {}

} // namespace godot
#endif
