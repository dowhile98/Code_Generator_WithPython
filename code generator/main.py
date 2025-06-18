
import yaml
from jinja2 import Environment, FileSystemLoader

def load_config(yaml_path):
    """
    Carga el YAML de configuración.
    Se espera que contenga al menos:
      - project: nombre del proyecto
      - file: nombre base (p.ej. "tasks" o "config")
      - tasks: lista de dicts con al menos name, stack_size, priority, task_param
    Devuelve un dict con claves project, file, tasks (lista, puede estar vacía).
    """
    with open(yaml_path, 'r') as f:
        cfg = yaml.safe_load(f)
    if not isinstance(cfg, dict):
        raise TypeError("El YAML debe contener un mapping en nivel raíz.")
    if 'project' not in cfg or 'file' not in cfg:
        raise KeyError("El YAML debe contener al menos 'project' y 'file'.")
    # Asegurar que tasks sea lista
    if 'tasks' not in cfg or cfg['tasks'] is None:
        cfg['tasks'] = []
    elif not isinstance(cfg['tasks'], list):
        raise TypeError("'tasks' debe ser una lista de definiciones de tarea.")
    # Opcional: validar cada tarea tiene 'name', 'stack_size', 'priority', 'task_param'
    for idx, task in enumerate(cfg['tasks']):
        if not isinstance(task, dict):
            raise TypeError(f"Tarea en índice {idx} no es un mapping.")
        for key in ('name', 'stack_size', 'priority', 'task_param'):
            if key not in task:
                raise KeyError(f"En tasks[{idx}] falta clave '{key}'.")
    return cfg

def render_config_header(cfg, env, output_dir='.'):
    """
    Renderiza la plantilla config.h.j2 usando los datos en cfg.
    Escribe el archivo: <project>_<file>_config.h en output_dir.
    """
    template = env.get_template('config.h.j2')
    rendered = template.render(
        project=cfg['project'],
        file=cfg['file'],
        tasks=cfg['tasks']
    )
    out_name = f"{cfg['project']}_{cfg['file']}_config.h"
    out_path = f"{output_dir}/{out_name}"
    with open(out_path, 'w') as f:
        f.write(rendered)
    print(f"Generado: {out_path}")

def render_task_header(cfg, env, output_dir='.'):
    """
    Renderiza la plantilla tasks.h.j2 usando los datos en cfg.
    Escribe el archivo: <project>_<file>.h en output_dir.
    """
    template = env.get_template('tasks.h.j2')
    rendered = template.render(
        project=cfg['project'],
        file=cfg['file'],
        tasks=cfg['tasks']
    )
    out_name = f"{cfg['project']}_{cfg['file']}.h"
    out_path = f"{output_dir}/{out_name}"
    with open(out_path, 'w') as f:
        f.write(rendered)
    print(f"Generado: {out_path}")

def render_task_source(cfg, env, output_dir='.'):
    """
    Renderiza la plantilla tasks.c.j2 usando los datos en cfg.
    Escribe el archivo: <project>_<file>.c en output_dir.
    """
    template = env.get_template('tasks.c.j2')
    rendered = template.render(
        project=cfg['project'],
        file=cfg['file'],
        tasks=cfg['tasks']
    )
    out_name = f"{cfg['project']}_{cfg['file']}.c"
    out_path = f"{output_dir}/{out_name}"
    with open(out_path, 'w') as f:
        f.write(rendered)
    print(f"Generado: {out_path}")


def main():
    import argparse
    parser = argparse.ArgumentParser(description="Generar config.h y tasks.h desde YAML y plantillas")
    parser.add_argument('yaml', help="Ruta al archivo YAML de configuración")
    parser.add_argument('--templates', default='templates', help="Directorio donde están las plantillas Jinja2")
    parser.add_argument('--outdir', default='.', help="Directorio de salida para los archivos generados")
    args = parser.parse_args()

    # Cargar configuración
    cfg = load_config(args.yaml)

    # Preparar Jinja2
    env = Environment(
        loader=FileSystemLoader(args.templates),
        trim_blocks=True,
        lstrip_blocks=True
    )

    # Generar ambos headers
    render_config_header(cfg, env, output_dir=args.outdir)
    render_task_header(cfg, env, output_dir=args.outdir)
    render_task_source(cfg, env, output_dir=args.outdir)

if __name__ == "__main__":
    main()
