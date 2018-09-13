#pragma once

#include "../util/config/config.h"

#include "../dxvk/dxvk_include.h"

#include "dxgi_include.h"

namespace dxvk {
  
  /**
   * \brief DXGI options
   * 
   * Per-app options that control the
   * behaviour of some DXGI classes.
   */
  struct DxgiOptions {
    DxgiOptions(const Config& config);

    /// Defer surface creation until first present call. This
    /// fixes issues with games that create multiple swap chains
    /// for a single window that may interfere with each other.
    bool deferSurfaceCreation;

    /// Override maximum frame latency if the app specifies
    /// a higher value. May help with frame timing issues.
    int32_t maxFrameLatency;

    /// Override PCI vendor and device IDs reported to the
    /// application. This may make apps think they are running
    /// on a different GPU than they do and behave differently.
    int32_t customVendorId;
    int32_t customDeviceId;
    
    /// Override maximum reported VRAM size. This may be
    /// useful for some 64-bit games which do not support
    /// more than 4 GiB of VRAM.
    VkDeviceSize maxDeviceMemory;
    VkDeviceSize maxSharedMemory;

    /// Back buffer count for the Vulkan swap chain.
    /// Overrides DXGI_SWAP_CHAIN_DESC::BufferCount.
    int32_t numBackBuffers;

    /// Sync interval. Overrides the value
    /// passed to IDXGISwapChain::Present.
    int32_t syncInterval;
  };
  
}
