/** @file brass_databasereplicator.h
 * @brief Support for brass database replication
 */
/* Copyright 2008 Lemur Consulting Ltd
 * Copyright 2009,2010,2011 Olly Betts
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301
 * USA
 */

#ifndef XAPIAN_INCLUDED_BRASS_DATABASEREPLICATOR_H
#define XAPIAN_INCLUDED_BRASS_DATABASEREPLICATOR_H

#include "backends/databasereplicator.h"

class BrassDatabaseReplicator : public Xapian::DatabaseReplicator {
    private:
	/** Path of database.
	 */
	std::string db_dir;

	/** Process a chunk which holds a base block.
	 */
	void process_changeset_chunk_base(const std::string & tablename,
					  std::string & buf,
					  RemoteConnection & conn,
					  double end_time) const;

	/** Process a chunk which holds a list of changed blocks in the
	 *  database.
	 */
	void process_changeset_chunk_blocks(const std::string & tablename,
					    std::string & buf,
					    RemoteConnection & conn,
					    double end_time) const;

    public:
	BrassDatabaseReplicator(const std::string & db_dir_);

	/** Virtual methods of DatabaseReplicator. */
	//@{
	bool check_revision_at_least(const std::string & rev,
				     const std::string & target) const;
	std::string apply_changeset_from_conn(RemoteConnection & conn,
					      double end_time,
					      bool valid) const;
	std::string get_uuid() const;
	//@}
};

#endif /* XAPIAN_INCLUDED_BRASS_DATABASEREPLICATOR_H */
