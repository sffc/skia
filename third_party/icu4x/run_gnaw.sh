#/usr/bin/env bash

export CARGO_GNAW_PATH=/home/sffc/projects/fuchsia/tools/cargo-gnaw
export SKIA_PATH=/home/sffc/projects/skia

cd "$CARGO_GNAW_PATH"

cargo run -- --manifest-path "$SKIA_PATH/third_party/externals/icu4x/ffi/diplomat/Cargo.toml" --project-root "$SKIA_PATH" --output "$SKIA_PATH/third_party/icu4x/host/BUILD.gn"

cargo run -- --manifest-path "$SKIA_PATH/third_party/externals/icu4x/ffi/diplomat/Cargo.toml" --project-root "$SKIA_PATH" --output "$SKIA_PATH/third_party/icu4x/target/BUILD.gn"
