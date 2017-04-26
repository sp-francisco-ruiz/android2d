//
// Created by fjruiz.
//
#include <jni.h>

#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

#include "native-lib.h"
#include "engine/application.h"
#include "platform/androidwindow.h"
#include "platform/androidfilemanager.h"
#include "game/game.h"

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnStart(JNIEnv* jenv, jobject obj)
{
    engine::Application::GetInstance().SetGame(new game::Game());
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnResume(JNIEnv* jenv, jobject obj)
{
    engine::Application::GetInstance().Start();
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnPause(JNIEnv* jenv, jobject obj)
{
    engine::Application::GetInstance().Stop();
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnStop(JNIEnv* jenv, jobject obj)
{
    engine::Application::GetInstance().SetGame(nullptr);
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_OnPress(JNIEnv* jenv, jobject obj)
{
    engine::Application::GetInstance().OnPressed();
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_SetSurface(JNIEnv* jenv, jobject obj, jobject surface)
{
    if (surface != 0)
    {
        ANativeWindow *window = ANativeWindow_fromSurface(jenv, surface);
        platform::AndroidWindow* platformWindow = new platform::AndroidWindow();
        platformWindow->SetWindow(window);
        engine::Application::GetInstance().SetWindow(platformWindow);
    }
    else
    {
        engine::Application::GetInstance().SetWindow(nullptr);
    }

    return;
}

JNIEXPORT void JNICALL Java_gumgun_es_a2dandroid_MainActivity_SetAssetManager(JNIEnv* jenv, jobject obj, jobject manager)
{
    auto assets = AAssetManager_fromJava(jenv, manager);
    platform::AndroidFileManager* fm = new platform::AndroidFileManager();
    fm->SetAssetManager(assets);
    engine::Application::GetInstance().SetFilesManager(fm);
}