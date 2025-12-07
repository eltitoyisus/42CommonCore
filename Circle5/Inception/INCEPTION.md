# Inception

## Description

Inception is a system administration project that introduces you to Docker and containerization. You'll set up a complete infrastructure using Docker Compose with multiple services running in separate containers.

## Project Overview

Create a small infrastructure composed of different services using Docker and Docker Compose. Each service must run in a dedicated container, and the entire infrastructure must be set up with your own Dockerfiles.

This project teaches you:
- Docker and containerization concepts
- Docker Compose orchestration
- Service configuration and networking
- Volume management
- TLS/SSL certificate setup
- Web server configuration
- Database administration
- Container security best practices

## Mandatory Services

You must set up the following services in separate containers:

### 1. NGINX (with TLSv1.2 or TLSv1.3)
- Web server acting as the entry point
- Configured with SSL/TLS certificates
- Listens on port 443 only (HTTPS)
- Serves WordPress website

### 2. WordPress (with php-fpm)
- Content management system
- Runs with PHP-FPM (no nginx or Apache)
- Connects to MariaDB database
- Configured with environment variables

### 3. MariaDB
- Database server for WordPress
- Persistent data storage
- No password for root in database
- Configured users and permissions

## Container Requirements

### Docker Images
- Use **penultimate stable version** of Alpine or Debian
- Build your own Dockerfiles (one per service)
- No pre-built images from DockerHub (except base Alpine/Debian)
- No `latest` tag

### Container Names
Must follow naming convention:
- NGINX: `nginx`
- WordPress: `wordpress`
- MariaDB: `mariadb`

### Network
- Containers must communicate through a Docker network
- NGINX is the only entry point (port 443)

### Volumes
- One volume for WordPress database
- One volume for WordPress website files
- Volumes must be available in `/home/login/data` on host

### Environment Variables
- Store sensitive information in `.env` file
- Not hardcoded in Dockerfiles
- `.env` file at root of `srcs` directory

## Directory Structure

```
Inception/
├── Makefile
├── README.md
├── setup.sh              # Setup script
├── setup-bonus.sh        # Bonus setup
└── srcs/
    ├── .env              # Environment variables (in .gitignore)
    ├── docker-compose.yml
    └── requirements/
        ├── mariadb/
        │   ├── Dockerfile
        │   ├── conf/
        │   └── tools/
        ├── nginx/
        │   ├── Dockerfile
        │   ├── conf/
        │   └── tools/
        └── wordpress/
            ├── Dockerfile
            ├── conf/
            └── tools/
```

## Configuration Requirements

### Domain Name
- Configure `login.42.fr` (replace `login` with your username)
- Point to your local IP
- Add to `/etc/hosts` file
```
127.0.0.1 login.42.fr
```

### Volumes Path
```
/home/login/data/wordpress
/home/login/data/mariadb
```

### SSL/TLS
- Configure NGINX with TLSv1.2 or TLSv1.3
- Generate self-signed SSL certificate or use tools like mkcert

## Docker Compose

### docker-compose.yml Example Structure
```yaml
version: '3'

services:
  mariadb:
    build: ./requirements/mariadb
    container_name: mariadb
    volumes:
      - mariadb_data:/var/lib/mysql
    networks:
      - inception
    env_file:
      - .env
    restart: always

  wordpress:
    build: ./requirements/wordpress
    container_name: wordpress
    depends_on:
      - mariadb
    volumes:
      - wordpress_data:/var/www/html
    networks:
      - inception
    env_file:
      - .env
    restart: always

  nginx:
    build: ./requirements/nginx
    container_name: nginx
    depends_on:
      - wordpress
    ports:
      - "443:443"
    volumes:
      - wordpress_data:/var/www/html
    networks:
      - inception
    env_file:
      - .env
    restart: always

volumes:
  mariadb_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/login/data/mariadb

  wordpress_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/login/data/wordpress

networks:
  inception:
    driver: bridge
```

## Makefile Rules

```bash
make        # Build and start containers
make up     # Start containers
make down   # Stop containers
make clean  # Stop and remove containers
make fclean # Clean everything including volumes
make re     # Rebuild everything
```

## Bonus Features (Optional)

Additional services to implement:
- **Redis cache** - For WordPress performance
- **FTP server** - For WordPress file management
- **Static website** - (Not PHP) Simple showcase site
- **Adminer** - Database management tool
- **Custom service** - Any useful service of your choice

## Best Practices

### Dockerfiles
- Use multi-stage builds when appropriate
- Minimize layers
- Don't run processes as root when possible
- Clean up in the same layer (RUN command)
- Use `.dockerignore` file

### Security
- No passwords in Dockerfiles or docker-compose.yml
- Use environment variables for sensitive data
- Run services with least privileges
- Keep containers updated

### Performance
- Use appropriate base images (Alpine for smaller size)
- Optimize image layers
- Use volume mounts efficiently

## Common Commands

### Docker
```bash
docker ps                    # List running containers
docker ps -a                 # List all containers
docker images               # List images
docker logs <container>     # View container logs
docker exec -it <container> sh  # Access container shell
docker-compose up -d        # Start in detached mode
docker-compose down         # Stop and remove containers
docker-compose logs -f      # Follow logs
```

### Testing
```bash
# Access WordPress
https://login.42.fr

# Check container status
docker-compose ps

# View logs
docker-compose logs nginx
docker-compose logs wordpress
docker-compose logs mariadb

# Access container
docker exec -it mariadb sh
docker exec -it wordpress sh
docker exec -it nginx sh
```

## Troubleshooting

Common issues:
- **Port conflicts**: Ensure port 443 is free
- **Permission issues**: Check volume mount permissions
- **Network issues**: Verify container networking
- **Database connection**: Check MariaDB credentials
- **SSL certificate**: Ensure proper certificate generation

## Skills Acquired

- Docker containerization
- Docker Compose orchestration
- Service architecture design
- NGINX configuration
- WordPress administration
- MariaDB database management
- SSL/TLS certificate setup
- Environment variable management
- System administration
- Infrastructure as Code
- Container networking
- Volume management
- Security best practices

## Circle

**Circle 5** - Containerization and infrastructure project at 42 School
