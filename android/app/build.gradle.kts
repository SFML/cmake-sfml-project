plugins {
    alias(libs.plugins.android.application)
    alias(libs.plugins.kotlin.android)
}

android {
    namespace = "com.example.cmakesfmlandroidproject"
    compileSdk {
        version = release(36)
    }

    defaultConfig {
        applicationId = "com.example.cmakesfmlandroidproject"
        minSdk = 24
        targetSdk = 36
        versionCode = 1
        versionName = "1.0"
    }

    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_11
        targetCompatibility = JavaVersion.VERSION_11
    }

    kotlinOptions {
        jvmTarget = "11"
    }

    externalNativeBuild {
        cmake {
            path = file("../../CMakeLists.txt")
            version  = "3.28.0+"
        }
    }
}