{
  'targets': [
    {
      'target_name': 'controller',
      'sources': [
        'nativeController.cc',
      ],
      'include_dirs': [
        '/home/felipe/main_controller/controller/include',
      ],
      "libraries": [
        '/usr/local/lib/libraryController/libmaincontroller.so'
      ],
      'ldflags': [
        '-L/usr/local/lib/libraryController/',
        '-lmaincontroller',
      ],
    }
  ]
}