load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "string_view",
    hdrs = [
        "string_view.h",
    ],
)

cc_test(
    name = "test_string_view",
    # size = "small",
    srcs = ["test.cpp"],
    deps = [
        ":string_view",
        "//tools/bazel:catch2",
        "//tools/util",
    ],
)
