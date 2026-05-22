#pragma once
#ifdef TOOLS_ENABLED
#include <godot_cpp/classes/editor_debugger_plugin.hpp>
#include <godot_cpp/classes/editor_debugger_session.hpp>

namespace godot {

class MrpDebuggerPlugin : public EditorDebuggerPlugin {
    GDCLASS(MrpDebuggerPlugin, EditorDebuggerPlugin)

    Ref<EditorDebuggerSession> _current_session;
    bool _session_active = false;

    void _session_started(int32_t p_session_id);
    void _session_stopped(int32_t p_session_id);
    void _session_breaked(bool p_can_debug, int32_t p_session_id);
    void _session_continued(int32_t p_session_id);

public:
    virtual void _setup_session(int32_t p_session_id) override;

protected:
    static void _bind_methods();
};

} // namespace godot
#endif
