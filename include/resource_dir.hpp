#pragma once

#include "raylib-cpp/raylib-cpp.hpp"
#include "string"



// #if defined(__cplusplus)
// extern "C" {            // Prevents name mangling of functions
// #endif
    
//     inline static bool SearchAndSetResourceDir(const char* folderName)
//     {
//         // check the working dir
//         if (DirectoryExists(folderName))
//         {
//             ChangeDirectory(TextFormat("%s/%s", GetWorkingDirectory(), folderName));
//             return true;
//         }

//         const char* appDir = GetApplicationDirectory();
       
//         // check the applicationDir
//         const char* dir = TextFormat("%s%s", appDir, folderName);
//         if (DirectoryExists(dir))
//         {
//             ChangeDirectory(dir);
//             return true;
//         }

//         // check one up from the app dir
//         dir = TextFormat("%s../%s", appDir, folderName);
//         if (DirectoryExists(dir))
//         {
//             ChangeDirectory(dir);
//             return true;
//         }

//         // check two up from the app dir
//         dir = TextFormat("%s../../%s", appDir, folderName);
//         if (DirectoryExists(dir))
//         {
//             ChangeDirectory(dir);
//             return true;
//         }

//         // check three up from the app dir
//         dir = TextFormat("%s../../../%s", appDir, folderName);
//         if (DirectoryExists(dir))
//         {
//             ChangeDirectory(dir);
//             return true;
//         }

//         return false;
//     }

// #if defined(__cplusplus)
// }
// #endif