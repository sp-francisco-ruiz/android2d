//
// Created by fjruiz on 14/04/2017.
//

#include <jni.h>

#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <string>

#include "native-lib.h"
#include "engine/utils/logger.h"
#include "engine/platform/application.h"

const std::string LOG_TAG("JNI");

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnStart(JNIEnv* jenv, jobject obj)
{
    LOG_INFO("OnStart a");
    engine::platform::Application::GetSharedApp().Start();
    LOG_INFO("OnStart b");
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnResume(JNIEnv* jenv, jobject obj)
{
    LOG_INFO("OnResume a");
    engine::platform::Application::GetSharedApp().Resume();
    LOG_INFO("OnResume b");
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnPause(JNIEnv* jenv, jobject obj)
{
    engine::platform::Application::GetSharedApp().Pause();
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnStop(JNIEnv* jenv, jobject obj)
{
    LOG_INFO("OnStop a");
    engine::platform::Application::GetSharedApp().Stop();
    LOG_INFO("OnStop b");
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnPress(JNIEnv* jenv, jobject obj)
{
    LOG_INFO("OnPress a");
    engine::platform::Application::GetSharedApp().OnPressed();
    LOG_INFO("OnPress b");
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_SetSurface(JNIEnv* jenv, jobject obj, jobject surface)
{
    LOG_INFO("SetSurface a");
    if (surface != 0)
    {
        ANativeWindow *window = ANativeWindow_fromSurface(jenv, surface);
        engine::platform::Application::GetSharedApp().SetWindow(window);
    }
    else
    {
        engine::platform::Application::GetSharedApp().SetWindow(nullptr);
    }
    LOG_INFO("SetSurface b");

    return;
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_SetAssetManager(JNIEnv* jenv, jobject obj, jobject manager)
{
    auto assets = AAssetManager_fromJava(jenv, manager);
    engine::platform::Application::GetSharedApp().SetAssets(assets);
}