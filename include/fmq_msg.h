/*  =========================================================================
    fmq_msg.h
    
    Generated codec header for fmq_msg
    -------------------------------------------------------------------------
    Copyright (c) 1991-2012 iMatix Corporation -- http://www.imatix.com
    Copyright other contributors as noted in the AUTHORS file.

    This file is part of FILEMQ, see http://filemq.org.

    This is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the
    Free Software Foundation; either version 3 of the License, or (at your
    option) any later version.

    This software is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTA-
    BILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General
    Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program. If not, see http://www.gnu.org/licenses/.
    =========================================================================
*/

#ifndef __FMQ_MSG_H_INCLUDED__
#define __FMQ_MSG_H_INCLUDED__

/*  These are the fmq_msg messages

    OHAI - Client opens peering
        protocol      string 
        version       octet 
        identity      octets [16]

    ORLY - Server challenges the client to authenticate itself
        mechanisms    strings 
        challenge     frame 

    YARLY - Client responds with authentication information
        mechanism     string 
        response      frame 

    OHAI_OK - Server grants the client access

    ICANHAZ - Client subscribes to a path
        path          string 
        options       dictionary 

    ICANHAZ_OK - Server confirms the subscription

    NOM - Client sends credit to the server
        credit        number 
        receipts      strings 

    CHEEZBURGER - The server sends a chunk of file data
        headers       dictionary 
        chunk         frame 

    HUGZ - Client or server sends a heartbeat

    HUGZ_OK - Client or server answers a heartbeat

    KTHXBAI - Client closes the peering

    SRSLY - Server refuses client due to access rights
        reason        string 

    RTFM - Server tells client it sent an invalid message
        reason        string 
*/

#define FMQ_MSG_OHAI                        1
#define FMQ_MSG_ORLY                        2
#define FMQ_MSG_YARLY                       3
#define FMQ_MSG_OHAI_OK                     4
#define FMQ_MSG_ICANHAZ                     5
#define FMQ_MSG_ICANHAZ_OK                  6
#define FMQ_MSG_NOM                         7
#define FMQ_MSG_CHEEZBURGER                 8
#define FMQ_MSG_HUGZ                        9
#define FMQ_MSG_HUGZ_OK                     10
#define FMQ_MSG_KTHXBAI                     11
#define FMQ_MSG_SRSLY                       128
#define FMQ_MSG_RTFM                        129
#define FMQ_MSG_IDENTITY_SIZE               16

#ifdef __cplusplus
extern "C" {
#endif

//  Opaque class structure
typedef struct _fmq_msg_t fmq_msg_t;

//  Create a new fmq_msg
fmq_msg_t *
    fmq_msg_new (int id);

//  Destroy the fmq_msg
void
    fmq_msg_destroy (fmq_msg_t **self_p);

//  Receive and parse a fmq_msg from the socket
fmq_msg_t *
    fmq_msg_recv (void *socket);

//  Send the fmq_msg to the socket, and destroy it
void
    fmq_msg_send (fmq_msg_t **self_p, void *socket);

//  Print contents of message to stdout
void
    fmq_msg_dump (fmq_msg_t *self);

//  Get/set the message address
zframe_t *
    fmq_msg_address (fmq_msg_t *self);
void
    fmq_msg_address_set (fmq_msg_t *self, zframe_t *address);

//  Get the fmq_msg id
int
    fmq_msg_id (fmq_msg_t *self);
void
    fmq_msg_id_set (fmq_msg_t *self, int id);

//  Get/set the identity field
byte *
    fmq_msg_identity (fmq_msg_t *self);
void
    fmq_msg_identity_set (fmq_msg_t *self, byte *identity);

//  Iterate through the mechanisms field, and append a mechanisms value
char *
    fmq_msg_mechanisms_first (fmq_msg_t *self);
char *
    fmq_msg_mechanisms_next (fmq_msg_t *self);
void
    fmq_msg_mechanisms_append (fmq_msg_t *self, char *format, ...);
size_t
    fmq_msg_mechanisms_size (fmq_msg_t *self);

//  Get/set the challenge field
zframe_t *
    fmq_msg_challenge (fmq_msg_t *self);
void
    fmq_msg_challenge_set (fmq_msg_t *self, zframe_t *frame);

//  Get/set the mechanism field
char *
    fmq_msg_mechanism (fmq_msg_t *self);
void
    fmq_msg_mechanism_set (fmq_msg_t *self, char *format, ...);

//  Get/set the response field
zframe_t *
    fmq_msg_response (fmq_msg_t *self);
void
    fmq_msg_response_set (fmq_msg_t *self, zframe_t *frame);

//  Get/set the path field
char *
    fmq_msg_path (fmq_msg_t *self);
void
    fmq_msg_path_set (fmq_msg_t *self, char *format, ...);

//  Get/set a value in the options dictionary
char *
    fmq_msg_options_string (fmq_msg_t *self, char *key, char *default_value);
int64_t
    fmq_msg_options_number (fmq_msg_t *self, char *key, int64_t default_value);
void
    fmq_msg_options_insert (fmq_msg_t *self, char *key, char *format, ...);
size_t
    fmq_msg_options_size (fmq_msg_t *self);

//  Get/set the credit field
int64_t
    fmq_msg_credit (fmq_msg_t *self);
void
    fmq_msg_credit_set (fmq_msg_t *self, int64_t credit);

//  Iterate through the receipts field, and append a receipts value
char *
    fmq_msg_receipts_first (fmq_msg_t *self);
char *
    fmq_msg_receipts_next (fmq_msg_t *self);
void
    fmq_msg_receipts_append (fmq_msg_t *self, char *format, ...);
size_t
    fmq_msg_receipts_size (fmq_msg_t *self);

//  Get/set a value in the headers dictionary
char *
    fmq_msg_headers_string (fmq_msg_t *self, char *key, char *default_value);
int64_t
    fmq_msg_headers_number (fmq_msg_t *self, char *key, int64_t default_value);
void
    fmq_msg_headers_insert (fmq_msg_t *self, char *key, char *format, ...);
size_t
    fmq_msg_headers_size (fmq_msg_t *self);

//  Get/set the chunk field
zframe_t *
    fmq_msg_chunk (fmq_msg_t *self);
void
    fmq_msg_chunk_set (fmq_msg_t *self, zframe_t *frame);

//  Get/set the reason field
char *
    fmq_msg_reason (fmq_msg_t *self);
void
    fmq_msg_reason_set (fmq_msg_t *self, char *format, ...);

//  Self test of this class
int
    fmq_msg_test (bool verbose);
    
#ifdef __cplusplus
}
#endif

#endif
