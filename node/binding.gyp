{
  'targets': [
    {
      'target_name': 'controller',
      'sources': [
        'nativeController.cc',
      ],
      'include_dirs': [
        '/home/felipe/main_controller/controller/include',
        '/usr/lib/jvm/java-1.7.0-openjdk-amd64/include',
      ],
      "libraries": [
        '/usr/local/lib/libraryController/libmaincontroller.so',
      ],
      'ldflags': [
        '-L/usr/local/lib/libraryController/',
        '-lmaincontroller',
        '-L/usr/lib/jvm/java-7-openjdk-amd64/jre/lib/amd64/server/',
        '-ljvm',
      ],
    }
  ]
}