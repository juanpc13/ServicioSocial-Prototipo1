-- Database generated with pgModeler (PostgreSQL Database Modeler).
-- pgModeler  version: 0.9.2-beta
-- PostgreSQL version: 9.6
-- Project Site: pgmodeler.io
-- Model Author: ---


-- Database creation must be done outside a multicommand file.
-- These commands were put in this file only as a convenience.
-- -- object: prototipo1 | type: DATABASE --
-- -- DROP DATABASE IF EXISTS prototipo1;
-- CREATE DATABASE prototipo1;
-- -- ddl-end --
-- 

-- object: public.data | type: TABLE --
-- DROP TABLE IF EXISTS public.data CASCADE;
CREATE TABLE public.data (
	id_data serial NOT NULL,
	date_time timestamp DEFAULT CURRENT_TIMESTAMP,
	latitude double precision,
	longitude double precision,
	altitude double precision,
	presion double precision,
	humedad double precision,
	temperatura double precision,
	"co2A" double precision,
	"co2B" double precision,
	h2s double precision,
	so2 double precision,
	CONSTRAINT data_pk PRIMARY KEY (id_data)

);
-- ddl-end --
ALTER TABLE public.data OWNER TO postgres;
-- ddl-end --


