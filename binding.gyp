{
  "targets": [
    {
      "target_name": "crash",
      "sources": [ "crash.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
