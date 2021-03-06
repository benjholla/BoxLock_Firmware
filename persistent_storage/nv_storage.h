/**
 * \file
 *
 * \brief Persistent Storage declaration.
 *
 * Copyright (C) 2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _NV_STORAGE_H_INCLUDED
#define _NV_STORAGE_H_INCLUDED

#include <compiler.h>
#include <err_codes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Initialize persistent storage
 */
void nv_storage_init(void);

/**
 * \brief Write an item to the persistent storage
 *
 * \param[in] id The ID of an item to store
 * \param[in] offset The offset inside the given item to start writing to
 * \param[in] data Data to write
 * \param[in] size The size of the data to write
 *
 * \return Status of the operation
 */
int32_t nv_storage_write(const uint16_t id, const uint16_t offset, const uint8_t *const data, const uint16_t size);

/**
 * \brief Read an item from the persistent storage
 *
 * \param[in] id The ID of an item to store
 * \param[in] offset The offset inside the given item to start reading from
 * \param[in] data Data buffer to read data to
 * \param[in] size The size of the data buffer
 *
 * \return Status of the operation
 */
int32_t nv_storage_read(const uint16_t id, const uint16_t offset, uint8_t *const data, const uint16_t size);

/**
 * \brief Retrieve the size of the given item
 *
 * \param[in] id The ID of an item
 *
 * \return The size of the given item or 0 if item does not exist
 */
uint16_t nv_storage_item_size(const uint16_t id);

/**
 * \brief Delete an item from the persistent storage
 *
 * \param[in] id The ID of an item to delete
 *
 * \return Status of the operation
 */
int32_t nv_storage_delete(const uint16_t id);

/**
 * \brief Delete all the items in the persistent storage
 *
 * \return Status of the operation
 */
int32_t nv_storage_erase_all(void);

/**
 * \brief Check whether an item with given ID exists in the persistent storage
 *
 * \param[in] id The ID of an item to store
 *
 * \return True if the item exists, otherwise false
 */
bool nv_storage_item_exists(const uint16_t id);

/**
 * \brief Force storage areas swapping.
 */
void nv_storage_force_packing(void);

/**
 * \brief Retrieve the amount of space left in storage
 *
 * \return The amount of space left in storage
 */
uint16_t nv_storage_space_left(void);

#ifdef __cplusplus
}
#endif

#endif /* _NV_STORAGE_H_INCLUDED */
