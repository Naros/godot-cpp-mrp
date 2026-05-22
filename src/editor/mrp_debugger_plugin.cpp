#include "mrp_debugger_plugin.h"
#ifdef TOOLS_ENABLED

namespace godot {

void MrpDebuggerPlugin::_session_started(int32_t p_session_id) {
    _session_active = true;
}

void MrpDebuggerPlugin::_session_stopped(int32_t p_session_id) {
    _session_active = false;
}

void MrpDebuggerPlugin::_session_breaked(bool p_can_debug, int32_t p_session_id) {}

void MrpDebuggerPlugin::_session_continued(int32_t p_session_id) {}

void MrpDebuggerPlugin::_setup_session(int32_t p_session_id) {
    const Ref<EditorDebuggerSession> session = get_session(p_session_id);
    if (session.is_valid()) {
        _current_session = session;

        session->connect("started",   callable_mp(this, &MrpDebuggerPlugin::_session_started).bind(p_session_id));
        session->connect("stopped",   callable_mp(this, &MrpDebuggerPlugin::_session_stopped).bind(p_session_id));
        session->connect("breaked",   callable_mp(this, &MrpDebuggerPlugin::_session_breaked).bind(p_session_id));
        session->connect("continued", callable_mp(this, &MrpDebuggerPlugin::_session_continued).bind(p_session_id));
    }
}

void MrpDebuggerPlugin::_bind_methods() {}

} // namespace godot
#endif
