add_executable( Types main.cpp )
set_target_properties( Types
    PROPERTIES VS_DEBUGGER_ENVIRONMENT "PATH=$<TARGET_FILE_DIR:Poco::Foundation>;"
)
target_link_libraries( Types PRIVATE Poco::Foundation )
target_link_directories( Types PRIVATE Poco::Foundation )
