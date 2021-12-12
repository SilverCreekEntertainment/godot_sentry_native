#include "core/engine.h"
#include "register_types.h"

#include "sentry_object.h"

static Sentry* _sentry = NULL;

void register_godot_sentry_native_types() {
	ClassDB::register_class<Sentry>();

	// Automatically create singleton instance, this is so that sentry can be initialized as soon as possible
	// to catch any startup crashes
	_sentry = memnew(Sentry);
	Engine::get_singleton()->add_singleton(Engine::Singleton("Sentry", Sentry::get_singleton()));
}

void unregister_godot_sentry_native_types() {
	memdelete(_sentry);
}
